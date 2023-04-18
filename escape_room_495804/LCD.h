#ifndef LCD_H
#define LCD_H

#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

class LCD {
private:

public:
  LiquidCrystal_I2C i2c;

  LCD();
};

#endif
