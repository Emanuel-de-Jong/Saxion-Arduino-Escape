#include "src/hardware/LCD.h"

LCD::LCD()
    : i2c(FSTATUS_LCD, 16, 2)
{
}

void LCD::setup()
{
  i2c.init();
}
