#include "CSimon.h"

CSimon::CSimon()
    : buttonGreen(CSIMON_BUTTON_GREEN_PIN),
      buttonRed(CSIMON_BUTTON_RED_PIN),
      buttonYellow(CSIMON_BUTTON_YELLOW_PIN),
      buttonBlue(CSIMON_BUTTON_BLUE_PIN),
      buttons{buttonGreen, buttonRed, buttonYellow, buttonBlue},
      rgbLED(
          CSIMON_RGBLED_RED_PIN,
          CSIMON_RGBLED_GREEN_PIN,
          CSIMON_RGBLED_BLUE_PIN),
      simonColors{
          CSimonColor(buttonGreen, rgbLED.GREEN),
          CSimonColor(buttonRed, rgbLED.RED),
          CSimonColor(buttonYellow, rgbLED.YELLOW),
          CSimonColor(buttonBlue, rgbLED.BLUE),
      }
{
}

void CSimon::setup()
{
  buttonGreen.setup();
  buttonRed.setup();
  buttonYellow.setup();
  buttonBlue.setup();

  rgbLED.setup();

  createRandomSequence();

  rgbLED.setColor(sequence[sequenceIndex].rgb);
}

void CSimon::loop()
{
  if (!isAnyButtonPressed())
    return;

  if (isButtonPressedValid())
  {
    sequenceIndex++;
    if (sequenceIndex > (SEQUENCE_SIZE - 1))
    {
      Serial.println("Complete");
      createRandomSequence();
    }

    rgbLED.setColor(sequence[sequenceIndex].rgb);

    Serial.println("Right");
    delay(250);
  }
  else
  {
    Serial.println("Wrong");
  }
}

void CSimon::createRandomSequence()
{
  sequenceIndex = 0;

  // Give rand uptime as the seed to always get different random numbers
  std::srand((unsigned)millis());

  for (int i = 0; i < SEQUENCE_SIZE; i++)
  {
    sequence[i] = simonColors[std::rand() % 4];
  }
}

bool CSimon::isAnyButtonPressed()
{
  for (Button button : buttons)
  {
    if (button.isPressed())
      return true;
  }

  return false;
}

bool CSimon::isButtonPressedValid()
{
  Button buttonToPress = sequence[sequenceIndex].button;
  if (!buttonToPress.isPressed())
    return false;

  for (Button button : buttons)
  {
    if (button.isPressed() && !(button == buttonToPress))
      return false;
  }

  return true;
}
