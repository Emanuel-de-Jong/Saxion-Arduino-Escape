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

  // The number displayed on the left screen
  // Consists of NUM_1, BTN_1_PRESSES, NUM_2 and BTN_2_PRESSES
  int leftDisplay;

  // Slows down button reads to minimize a faulty button release because of a short contact failure
  const int BUTTON_COOLDOWN_TIME; 
  int millisSinceButtonCooldown = 0;

  bool isButtonPressed = false;

  // Stage 1 is NUM_1 and BTN_1_PRESSES
  // Stage 2 is NUM_2 and BTN_2_PRESSES
  int stage = 1;

  // Amount of times the same button is pressed in a row. Displayed on right screen
  int consecutiveBtnPressed = 1;
  int lastBtn = -1;

public:
  CRiddle();

  void setup();
  void loop();

  bool handleBtnPress();
  void checkStageComplete();
};

#endif
