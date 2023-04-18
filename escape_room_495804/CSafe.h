#ifndef CSAFE_H
#define CSAFE_H

#include <Arduino.h>

#include "globals.h"

#include "Buzzer.h"
#include "Potmeter.h"

class CSafe {
private:
  Buzzer buzzer;
  Potmeter potmeter;
public:
  CSafe();
  void setup();
  void loop();
};

#endif
