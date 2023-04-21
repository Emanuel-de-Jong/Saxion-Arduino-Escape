#ifndef CSAFE_H
#define CSAFE_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/challenges/Challenge.h"

#include "src/hardware/Buzzer.h"
#include "src/hardware/Potmeter.h"

#include "src/challenges/CSafeStage.h"

class CSafe : public Challenge
{
private:
  Buzzer &buzzer;
  Potmeter potmeter;

  int currentStageIndex = 0;
  CSafeStage stages[3];
  int stageCount = 3;

  const int CHECK_RATE;
  int millisSinceCheck = 0;

  const int COUNTDOWN_DURATION;

  int countdown;

public:
  CSafe(Buzzer &buzzer);

  void setup();
  void loop();
};

#endif
