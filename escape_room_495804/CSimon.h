#ifndef CSIMON_H
#define CSIMON_H

#include <Arduino.h>

#include "globals.h"

#include "Button.h"
#include "RGBLED.h"

class CSimon {
private:
  Button buttonGreen;
  Button buttonRed;
  Button buttonYellow;
  Button buttonBlue;

  RGBLED rgbLED;

public:
  CSimon();
  
  void setup();
  void loop();
};

#endif
