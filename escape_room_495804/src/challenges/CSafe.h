// Turn the potmeter to the right spot multiple times

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
  const int STAGE_COUNT = 3;

  // Loop intervals (in milliseconds)
  const int CHECK_RATE;
  int millisSinceCheck = 0;

  // How long the potmeter should be in the right spot before going to the next stage
  const int COUNTDOWN_DURATION;
  int countdown;

public:
  CSafe(Buzzer &buzzer);

  void setup();
  void loop();
};

#endif
