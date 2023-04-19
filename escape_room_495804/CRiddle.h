#ifndef CRIDDLE_H
#define CRIDDLE_H

#include <Arduino.h>

#include <string>

#include "globals.h"

#include "LEDKey.h"

class CRiddle {
private:
  LEDKey ledKey;

  const int NUM_1;
  const int NUM_2;

  const int BTN_1_PRESSES;
  const int BTN_2_PRESSES;

  int leftDisplay;

  int stage = 0;

  int lastBtn = -1;
  int consecutiveBtnPressed = 1;

public:
  CRiddle();
  
  void setup();
  void loop();
};

#endif
