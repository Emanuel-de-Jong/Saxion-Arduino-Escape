#include "src/functions/FStatus.h"

FStatus::FStatus(CSafe &cSafe, CRiddle &cRiddle, CSimon &cSimon, CReaction &cReaction)
    : SOLVE_TIME(5 * 60),
      REFRESH_RATE(500),
      challenges{cSafe, cRiddle, cSimon, cReaction}
{
}

void FStatus::setup()
{
  lcd.setup();

  for (int i = 0; i < CHALLENGE_COUNT; i++) {
    lcd.i2c.createChar(i, challengeChars[i]);
  }

  lcd.i2c.createChar(6, uncheckedChar);
  lcd.i2c.createChar(7, checkedChar);

  lcd.i2c.backlight();
}

void FStatus::loop()
{
  if (millis() - millisSinceRefresh <= REFRESH_RATE)
    return;
  millisSinceRefresh = millis();

  updateChallengeStatuses();

  lcd.i2c.clear();
  lcd.i2c.home();

  printTime();
  printChallenges();
}

void FStatus::printTime()
{
  int timeRemaining = SOLVE_TIME - (millis() / 1000);
  int minutes = timeRemaining / 60;
  int seconds = timeRemaining % 60;

  lcd.i2c.printf("%d:%02d", minutes, seconds);
}

void FStatus::printChallenges()
{
  lcd.i2c.setCursor(0, 1);

  for (int i = 0; i < CHALLENGE_COUNT; i++) {
    lcd.i2c.write(i);
    lcd.i2c.write(challengeStatuses[i] ? 7 : 6);
  }
}

void FStatus::updateChallengeStatuses() {
  // Serial.println(challenges[3].getIsDone());
  // for (Challenge challenge : challenges) {
  //   challengeStatuses[challenge.getChallengeId()] = challenge.getIsDone();
  // }

  challengeStatuses[cSafe.getChallengeId()] = cSafe.getIsDone();
  challengeStatuses[cRiddle.getChallengeId()] = cRiddle.getIsDone();
  challengeStatuses[cSimon.getChallengeId()] = cSimon.getIsDone();
  challengeStatuses[cReaction.getChallengeId()] = cReaction.getIsDone();
}

bool FStatus::areAllChallengesDone() {
  for (bool isDone : challengeStatuses) {
    if (!isDone) {
      return false;
    }
  }

  return true;
}
