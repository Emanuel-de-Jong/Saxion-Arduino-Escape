#ifndef CREACTION_H
#define CREACTION_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/hardware/LED.h"

class CReaction
{
private:
  LED led1;
  LED led2;
  LED led3;

public:
  CReaction();

  void setup();
  void loop();
};

#endif
