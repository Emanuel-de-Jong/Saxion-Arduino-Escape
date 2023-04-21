#ifndef CSAFE_H
#define CSAFE_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/hardware/Buzzer.h"
#include "src/hardware/Potmeter.h"

#include "src/challenges/CSafeStage.h"

class CSafe
{
private:
  const int CHALLENGE_ID;

  Buzzer buzzer;
  Potmeter potmeter;

  int currentStageIndex = 0;
  CSafeStage stages[3];
  int stageCount = 3;

  const int CHECK_RATE;
  int millisSinceCheck = 0;

  const int COUNTDOWN_DURATION;

  int countdown;

  bool isDone = false;

public:
  CSafe();

  void setup();
  void loop();

  int getChallengeId();
};

#endif
