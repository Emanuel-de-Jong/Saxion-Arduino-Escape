#include "src/hardware/LCD.h"

LCD::LCD(int pin)
    : i2c(pin, 16, 2)
{
}

void LCD::setup()
{
  i2c.init();
}
