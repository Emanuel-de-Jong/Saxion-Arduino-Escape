#ifndef CSIMON_H
#define CSIMON_H

#include <Arduino.h>

#include "globals.h"

#include "Button.h"

class CSimon {
private:
  Button buttonGreen;
  Button buttonRed;
  Button buttonYellow;
  Button buttonBlue;

public:
  CSimon();
  
  void setup();
  void loop();
};

#endif
