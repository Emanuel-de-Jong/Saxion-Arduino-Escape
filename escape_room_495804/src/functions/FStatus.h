#ifndef FSTATUS_H
#define FSTATUS_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/challenges/Challenge.h"
#include "src/challenges/CSafe.h"
#include "src/challenges/CRiddle.h"
#include "src/challenges/CSimon.h"
#include "src/challenges/CReaction.h"

#include "src/hardware/LCD.h"

extern CSafe cSafe;
extern CRiddle cRiddle;
extern CSimon cSimon;
extern CReaction cReaction;

class FStatus
{
private:
  LCD lcd;

  const int SOLVE_TIME;

  const int CHALLENGE_COUNT = 4;
  Challenge challenges[4];
  bool challengeStatuses[4] = {
      false,
      false,
      false,
      false};

  const int REFRESH_RATE;
  int millisSinceRefresh = 0;

  byte uncheckedChar[8] = {
      B00000,
      B00000,
      B00000,
      B11111,
      B10001,
      B10001,
      B10001,
      B11111};
  byte checkedChar[8] = {
      B00000,
      B00000,
      B00000,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111};
    
  byte challengeChars[4][8] = {
    { // Safe
      B00000,
      B00000,
      B00000,
      B01110,
      B01110,
      B01110,
      B11111,
      B11111
    },
    { // Riddle
      B00000,
      B00000,
      B00000,
      B11100,
      B10100,
      B11100,
      B10100,
      B11101
    },
    { // Simon
      B00000,
      B00000,
      B00000,
      B11011,
      B11011,
      B00000,
      B11011,
      B11011
    },
    { // Reaction
      B00000,
      B00000,
      B00000,
      B10101,
      B00000,
      B00100,
      B01110,
      B00100
    }
  };

  void printTime();
  void printChallenges();
  void updateChallengeStatuses();
  bool areAllChallengesDone();

public:
  FStatus(CSafe &cSafe, CRiddle &cRiddle, CSimon &cSimon, CReaction &cReaction);

  void setup();
  void loop();
};

#endif
