#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

#include "globals.h"

#include "Button.h"

class CLock {
private:
  Button button;
public:
  CLock();
  void setup();
  void loop();
};

#endif
