#ifndef CRIDDLE_H
#define CRIDDLE_H

#include <Arduino.h>

#include <string>

#include "src/globals.h"

#include "src/challenges/Challenge.h"

#include "src/hardware/LEDKey.h"

class CRiddle : public Challenge
{
private:
  LEDKey ledKey;

  const int NUM_1;
  const int NUM_2;

  const int BTN_1_PRESSES;
  const int BTN_2_PRESSES;

  int leftDisplay;

  const int BUTTON_COOLDOWN_TIME;
  int millisSinceButtonCooldown = 0;

  bool isButtonPressed = false;

  int stage = 1;

  int lastBtn = -1;
  int consecutiveBtnPressed = 1;

public:
  CRiddle();

  void setup();
  void loop();
};

#endif
