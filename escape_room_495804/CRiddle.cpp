#include "CRiddle.h"

CRiddle::CRiddle()
    : ledKey(
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
          std::to_string(BTN_2_PRESSES)))
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
  int btn = ledKey.getPressedBtn();
  if (btn == -1)
    return;

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

  int num = stage == 0 ? NUM_1 : NUM_2;
  int btnPresses = stage == 0 ? BTN_1_PRESSES : BTN_2_PRESSES;
  if (consecutiveBtnPressed == btnPresses && btn == num - 1)
  {
    consecutiveBtnPressed = 0;
    ledKey.tm.DisplayDecNumNibble(leftDisplay, consecutiveBtnPressed);

    stage++;

    if (stage == 1)
    {
      ledKey.tm.setLEDs(0b1111000000000000);
    }
    else
    {
      ledKey.tm.setLEDs(0b0000000000000000);
    }
  }

  delay(250);
}
