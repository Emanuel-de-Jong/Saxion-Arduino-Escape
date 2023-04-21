#ifndef CREACTION_H
#define CREACTION_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/challenges/Challenge.h"

#include "src/hardware/LED.h"
#include "src/hardware/Button.h"

class CReaction : public Challenge
{
private:
  LED led1;
  LED led2;
  LED led3;

  LED &ledToHit;

  Button button;

  LED leds[3];
  const int LED_COUNT = 3;
  int ledIndex = 0;

  int SPEED; // The milliseconds a LED is on
  int millisSinceLEDOn = 0;

  bool isLeftToRight = true; // Is toggled to make the leds go back and forth.

  void turnAllLEDsOff();

public:
  CReaction();

  void setup();
  void loop();
};

#endif
