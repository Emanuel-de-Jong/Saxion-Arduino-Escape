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
      },
      // The starting stage is set to 3 to start with the first 3 colors of the sequence
      SEQUENCE_STARTING_STAGE(3),
      USER_INPUT_TIME(3000),
      BUTTON_COOLDOWN_TIME(20),
      COLOR_TIME(200),
      BLANK_TIME(100),
      COLOR_SEQUENCE_RESTART_TIME(2000)
{
  setChallengeId(2);
}

void CSimon::setup()
{
  for (Button button : buttons)
  {
    button.setup();
  }

  rgbLED.setup();

  createRandomSequence();
}

void CSimon::loop()
{
  if (getIsDone())
    return;

  if (millis() - millisSinceButtonCooldown <= BUTTON_COOLDOWN_TIME)
    return;
  millisSinceButtonCooldown = millis();

  checkButtonInput();
  showSequence();
}

// Checks if a button was pressed
void CSimon::checkButtonInput()
{
  if (isAnyButtonPressed())
  {
    if (isStageChanged)
      return;

    if (isButtonPressed)
      return;
    isButtonPressed = true;

    millisSinceUserInput = millis();

    // If this is the first button press since showing the sequence,
    // set sequenceIndex to 0 to restart the stage
    if (!isUserInputting)
    {
      isUserInputting = true;
      sequenceIndex = 0;
    }

    checkButtonInputValidity();
  }
  else if (isButtonPressed)
  {
    isButtonPressed = false;
  }
}

// Checks if the pressed button from checkButtonInput() is valid and handles it acordingly
void CSimon::checkButtonInputValidity()
{
  if (isButtonPressedValid())
  {
    sequenceIndex++;

    // If the sequence range of the stage is done
    if (sequenceIndex + 1 > sequenceStage)
    {
      sequenceIndex = 0;
      sequenceStage++; // Go to the next stage

      isStageChanged = true;

      // Make the LED green for a bit to indicate a pass
      rgbLED.setColor(rgbLED.GREEN);
      delay(200);
      rgbLED.turnOff();

      // If it was the last stage
      if (sequenceStage > SEQUENCE_SIZE)
      {
        setIsDone(true);
        return;
      }
    }
  }
  // On any wrong button input, restart the whole challenge
  else
  {
    // Reset the challenge and get a new sequence
    createRandomSequence();

    isStageChanged = true;

    // Make the LED red for a bit to indicate failure
    rgbLED.setColor(rgbLED.RED);
    delay(200);
    rgbLED.turnOff();
  }
}

// Shows the color sequence with the LEDs
void CSimon::showSequence()
{
  if (millis() - millisSinceUserInput > USER_INPUT_TIME)
  {
    // If this is the first showcase since a button press,
    // set sequenceIndex to 0 to restart the color sequence
    if (isUserInputting)
    {
      isUserInputting = false;

      isStageChanged = false;
      sequenceIndex = 0;
    }

    // If the LED has been on and off long enough, go to the next color
    if (millis() - millisSinceColorChange > COLOR_TIME + BLANK_TIME)
    {
      if (millis() - millisSinceColorSequenceRestart <= COLOR_SEQUENCE_RESTART_TIME)
        return;

      rgbLED.setColor(sequence[sequenceIndex].rgb);
      millisSinceColorChange = millis();

      sequenceIndex++;
      if (sequenceIndex + 1 > sequenceStage)
      {
        sequenceIndex = 0;
        millisSinceColorSequenceRestart = millis();
      }
    }
    // If the LED has been on long enough, turn it off
    else if (millis() - millisSinceColorChange > COLOR_TIME)
    {
      rgbLED.turnOff();
    }
  }
}

void CSimon::createRandomSequence()
{
  sequenceStage = SEQUENCE_STARTING_STAGE;
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

  // Return false if a wrong button was pressed
  // Even if the right button was pressed as well
  // Prevents spamming all buttons
  for (Button button : buttons)
  {
    if (button.isPressed() && !(button == buttonToPress))
      return false;
  }

  return true;
}
