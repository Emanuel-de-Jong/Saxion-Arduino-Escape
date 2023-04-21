#ifndef FSTATUS_H
#define FSTATUS_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/hardware/LCD.h"

class FStatus
{
private:
  LCD lcd;

  const int SOLVE_TIME;

  const int CHALLENGE_COUNT = 4;
  bool challenges[4] = {
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
  bool areAllChallengesDone();

public:
  FStatus();

  void setup();
  void loop();

  void setChallengeDone(int challengeId);
};

#endif
