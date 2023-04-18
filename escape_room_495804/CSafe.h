#ifndef CSAFE_H
#define CSAFE_H

#include <Arduino.h>

#include "globals.h"

#include "Button.h"

class CSafe {
private:
  Button button;
public:
  CSafe();
  void setup();
  void loop();
};

#endif
