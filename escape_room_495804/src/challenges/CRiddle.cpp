#include "src/challenges/CRiddle.h"

CRiddle::CRiddle()
    : CHALLENGE_ID(1),
      ledKey(
          CRIDDLE_LEDKEY_STROBE_PIN,
          CRIDDLE_LEDKEY_CLOCK_PIN,
          CRIDDLE_LEDKEY_DIO_PIN),
      NUM_1(5),
      NUM_2(8),
      BTN_1_PRESSES(2),
      BTN_2_PRESSES(5),
      leftDisplay(std::stoi(
          std::to_string(NUM_1) +
          std::to_string(BTN_1_PRESSES) +
          std::to_string(NUM_2) +
          std::to_string(BTN_2_PRESSES))),
      BUTTON_COOLDOWN_TIME(20)
{
}

void CRiddle::setup()
{
  ledKey.setup();

  ledKey.tm.displayIntNum(leftDisplay, false, TMAlignTextLeft);

  ledKey.tm.setLEDs(0b1111111100000000);
}

void CRiddle::loop()
{
  if (isDone)
    return;

  if (millis() - millisSinceButtonCooldown <= BUTTON_COOLDOWN_TIME)
    return;
  millisSinceButtonCooldown = millis();

  int btn = ledKey.getPressedBtn();
  if (btn == -1) {
    isButtonPressed = false;
    return;
  } else if (isButtonPressed) {
    return;
  }
  isButtonPressed = true;

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

  int num = stage == 1 ? NUM_1 : NUM_2;
  int btnPresses = stage == 1 ? BTN_1_PRESSES : BTN_2_PRESSES;
  if (consecutiveBtnPressed == btnPresses && btn == num - 1)
  {
    consecutiveBtnPressed = 0;
    ledKey.tm.DisplayDecNumNibble(leftDisplay, consecutiveBtnPressed);

    stage++;

    if (stage == 2)
    {
      ledKey.tm.setLEDs(0b1111000000000000);
    }
    else
    {
      ledKey.tm.setLEDs(0b0000000000000000);

      isDone = true;
      return;
    }
  }
}

int CRiddle::getChallengeId() {
  return CHALLENGE_ID;
}
