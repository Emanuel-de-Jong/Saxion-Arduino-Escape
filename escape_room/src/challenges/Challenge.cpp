#include "src/challenges/Challenge.h"

void Challenge::setup() {}

void Challenge::loop() {}

void Challenge::setChallengeId(int val)
{
  challengeId = val;
}

int Challenge::getChallengeId()
{
  return challengeId;
}

bool Challenge::getIsDone()
{
  return isDone;
}

void Challenge::setIsDone(bool val)
{
  isDone = val;
}
