#ifndef LEDKEY_H
#define LEDKEY_H

#include <Arduino.h>

#include <TM1638plus.h>

class LEDKey
{
public:
  TM1638plus tm;

  LEDKey(uint8_t strobePin, uint8_t clockPin, uint8_t dioPin);

  void setup();

  int getPressedBtn();
};

#endif
