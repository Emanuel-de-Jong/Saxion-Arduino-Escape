#include "src/challenges/CRiddle.h"

CRiddle::CRiddle()
    : ledKey(
          CRIDDLE_LEDKEY_STROBE_PIN,
          CRIDDLE_LEDKEY_CLOCK_PIN,
          CRIDDLE_LEDKEY_DIO_PIN),
      NUM_1(5),
      NUM_2(8),
      BTN_1_PRESSES(2),
      BTN_2_PRESSES(5),
      // The number on the left screen is dynamically created once here for clean code and high performance
      leftDisplay(std::stoi(
          std::to_string(NUM_1) +
          std::to_string(BTN_1_PRESSES) +
          std::to_string(NUM_2) +
          std::to_string(BTN_2_PRESSES))),
      BUTTON_COOLDOWN_TIME(20)
{
  setChallengeId(1);
}

void CRiddle::setup()
{
  ledKey.setup();

  ledKey.tm.displayIntNum(leftDisplay, false, TMAlignTextLeft);

  // Turn all LEDs on to indicate stage 1
  ledKey.tm.setLEDs(0b1111111100000000);
}

void CRiddle::loop()
{
  if (getIsDone())
    return;

  if (millis() - millisSinceButtonCooldown <= BUTTON_COOLDOWN_TIME)
    return;
  millisSinceButtonCooldown = millis();

  if (!handleBtnPress())
    return;

  checkStageComplete();
}

// Checks for button presses and if they are consecutive
// Returns false if no buttons are pressed or the same button has not yet been released
bool CRiddle::handleBtnPress() {
  int btn = ledKey.getPressedBtn();
  // No button pressed
  if (btn == -1)
  {
    isButtonPressed = false; // Set to false for possible button release
    return false;
  }
  // Same button still pressed
  else if (isButtonPressed)
  {
    return false;
  }
  isButtonPressed = true; // Set to true so the `else if` above is triggered next loop

  if (btn == lastBtn)
  {
    consecutiveBtnPressed++;
  }
  else
  {
    lastBtn = btn;
    consecutiveBtnPressed = 1;
  }

  ledKey.tm.DisplayDecNumNibble(leftDisplay, consecutiveBtnPressed);

  return true;
}

// Compares consecutive button presses against the stage requirements and increases the stage if met
void CRiddle::checkStageComplete() {
  int num = stage == 1 ? NUM_1 : NUM_2;
  int btnPresses = stage == 1 ? BTN_1_PRESSES : BTN_2_PRESSES;
  // Stage requirements are met if the right button (num) has been pressed the right amount of times (btnPresses)
  if (consecutiveBtnPressed == btnPresses && ledKey.getPressedBtn() == num - 1)
  {
    consecutiveBtnPressed = 0;
    ledKey.tm.DisplayDecNumNibble(leftDisplay, consecutiveBtnPressed);

    stage++;

    if (stage == 2)
    {
      // Turn only the right LEDs on to indicate stage 2
      ledKey.tm.setLEDs(0b1111000000000000);
    }
    else
    {
      // Turn all LEDs off to indicate completion
      ledKey.tm.setLEDs(0b0000000000000000);

      setIsDone(true);
    }
  }
}
