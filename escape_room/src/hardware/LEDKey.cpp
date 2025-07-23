#include "src/hardware/LEDKey.h"

LEDKey::LEDKey(uint8_t strobePin, uint8_t clockPin, uint8_t dioPin)
    : tm(strobePin, clockPin, dioPin)
{
}

void LEDKey::setup()
{
  tm.displayBegin();
}

// Returns the index of the first pressed button or -1 when no button is pressed
int LEDKey::getPressedBtn()
{
  uint8_t buttons = tm.readButtons();
  for (int i = 0; i < 8; i++)
  {
    if ((buttons >> i) & 0x01)
    {
      return i;
    }
  }

  return -1;
}
