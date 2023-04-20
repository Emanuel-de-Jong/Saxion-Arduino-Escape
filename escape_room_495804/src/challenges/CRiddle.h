#ifndef CRIDDLE_H
#define CRIDDLE_H

#include <Arduino.h>

#include <string>

#include "src/globals.h"

#include "src/hardware/LEDKey.h"

class CRiddle
{
private:
  LEDKey ledKey;

  const int NUM_1;
  const int NUM_2;

  const int BTN_1_PRESSES;
  const int BTN_2_PRESSES;

  int leftDisplay;

  const int WRITE_RATE;
  int millisSinceWrite = 0;

  int stage = 0;

  int lastBtn = -1;
  int consecutiveBtnPressed = 1;

  bool isDone = false;

public:
  CRiddle();

  void setup();
  void loop();
};

#endif
