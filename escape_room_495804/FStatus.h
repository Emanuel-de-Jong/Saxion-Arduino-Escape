#ifndef FSTATUS_H
#define FSTATUS_H

#include <Arduino.h>

#include "globals.h"

#include "LCD.h"

class FStatus {
private:
  LCD lcd;

  const int SOLVE_TIME;

  bool challenges[4] = {
    false,
    false,
    false,
    false
  };

  byte uncheckedChar[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B10001,
    B10001,
    B10001,
    B11111
  };
  byte checkedChar[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };
  byte lockChar[8] = {
    B00000,
    B00000,
    B00000,
    B01110,
    B01110,
    B01110,
    B11111,
    B11111
  };
  byte riddleChar[8] = {
    B00000,
    B00000,
    B00000,
    B11100,
    B10100,
    B11100,
    B10100,
    B11101
  };
  byte simonChar[8] = {
    B00000,
    B00000,
    B00000,
    B11011,
    B11011,
    B00000,
    B11011,
    B11011
  };
  byte wiringChar[8] = {
    B00000,
    B00000,
    B00000,
    B10101,
    B10101,
    B10101,
    B10101,
    B10101
  };

public:
  FStatus();
  void setup();
  void loop();
};

#endif
