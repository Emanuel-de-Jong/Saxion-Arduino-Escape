#ifndef CSAFE_H
#define CSAFE_H

#include <Arduino.h>

#include "globals.h"

#include "Buzzer.h"
#include "Potmeter.h"

#include "CSafeStage.h"

class CSafe {
private:
  Buzzer buzzer;
  Potmeter potmeter;

  int currentStageIndex = 0;
  int stageCount = 3;
  CSafeStage stages[3];
public:
  CSafe();
  void setup();
  void loop();
};

#endif
