#include "src/functions/FStatus.h"

FStatus::FStatus()
    : SOLVE_TIME(5 * 60),
      REFRESH_RATE(500)
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
    lcd.i2c.write(challenges[i] ? 7 : 6);
  }
}

bool FStatus::areAllChallengesDone() {
  for (bool isDone : challenges) {
    if (!isDone) {
      return false;
    }
  }

  return true;
}

void FStatus::setChallengeDone(int challengeId) {
  challenges[challengeId] = true;
}
