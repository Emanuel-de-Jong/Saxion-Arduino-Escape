#ifndef CRIDDLE_H
#define CRIDDLE_H

#include <Arduino.h>

#include "globals.h"

#include "LEDKey.h"

class CRiddle {
private:
  LEDKey ledKey;

public:
  CRiddle();
  
  void setup();
  void loop();
};

#endif
