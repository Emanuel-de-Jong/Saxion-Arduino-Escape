#include "src/challenges/CSimon.h"

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
          CSimonColor(buttonGreen, rgbLED.DARK_GREEN),
          CSimonColor(buttonRed, rgbLED.DARK_RED),
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
}

void CSimon::loop()
{
  if (isDone) return;

  delay(20);

  if (isAnyButtonPressed()) {
    if (isStageChanged) return;

    if (isButtonPressed) return;
    isButtonPressed = true;

    millisSinceUserInput = millis();

    if (!isUserInputting) {
      isUserInputting = true;
      sequenceIndex = 0;
    }

    if (isButtonPressedValid()) {
      sequenceIndex++;

      if (sequenceIndex + 1 > sequenceStage) {
        sequenceIndex = 0;
        sequenceStage++;

        isStageChanged = true;

        rgbLED.setColor(rgbLED.GREEN);
        delay(200);
        rgbLED.turnOff();

        if (sequenceStage > SEQUENCE_SIZE) {
          isDone = true;
          return;
        }
      }
    } else {
      createRandomSequence();

      isStageChanged = true;

      rgbLED.setColor(rgbLED.RED);
      delay(200);
      rgbLED.turnOff();
    }
  } else if (isButtonPressed) {
    isButtonPressed = false;
  }

  if (millis() - millisSinceUserInput > USER_INPUT_TIME) {
    if (isUserInputting) {
      isUserInputting = false;

      isStageChanged = false;
      sequenceIndex = 0;
    }

    if (millis() - millisSinceColorChange > COLOR_TIME + BLANK_TIME) {
      if (millis() - millisSinceColorSequenceRestart <= COLOR_SEQUENCE_RESTART_TIME) return;

      rgbLED.setColor(sequence[sequenceIndex].rgb);
      millisSinceColorChange = millis();

      sequenceIndex++;
      if (sequenceIndex + 1 > sequenceStage) {
        sequenceIndex = 0;
        millisSinceColorSequenceRestart = millis();
      }
    }
    else if (millis() - millisSinceColorChange > COLOR_TIME) {
      rgbLED.turnOff();
    }
  }
}

void CSimon::blink(RGB color) {
  rgbLED.setColor(color);
  delay(800);
  rgbLED.turnOff();
  delay(200);
}

void CSimon::createRandomSequence()
{
  sequenceStage = 1;
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
