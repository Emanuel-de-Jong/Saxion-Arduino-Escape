#include "src/functions/FStatus.h"

FStatus::FStatus(Buzzer &buzzer, CSafe *cSafe, CRiddle *cRiddle, CSimon *cSimon, CReaction *cReaction)
    : buzzer(buzzer),
      SOLVE_TIME(3 * 60),
      // SOLVE_TIME(3),
      REFRESH_RATE(500),
      challenges{cSafe, cRiddle, cSimon, cReaction}
{
}

void FStatus::setup()
{
  lcd.setup();

  for (int i = 0; i < CHALLENGE_COUNT; i++)
  {
    lcd.i2c.createChar(i, challengeChars[i]);
  }

  lcd.i2c.createChar(6, uncheckedChar);
  lcd.i2c.createChar(7, checkedChar);

  lcd.i2c.backlight();

  // challenges[0]->setIsDone(true);
  // challenges[1]->setIsDone(true);
  // challenges[2]->setIsDone(true);
  // challenges[3]->setIsDone(true);
}

void FStatus::loop()
{
  if (hasWon || hasLost)
    return;

  if (millis() - millisSinceRefresh <= REFRESH_RATE)
    return;
  millisSinceRefresh = millis();

  updateChallengeStatuses();
  if (areAllChallengesDone())
  {
    execWin();
    return;
  }

  if (getTimeRemaining() <= 0)
  {
    execLoss();
    return;
  }

  lcd.i2c.clear();
  lcd.i2c.home();

  printTime();
  printChallenges();
}

int FStatus::getTimeRemaining()
{
  return SOLVE_TIME - (millis() / 1000);
}

void FStatus::printTime()
{
  int timeRemaining = getTimeRemaining();
  int minutes = timeRemaining / 60;
  int seconds = timeRemaining % 60;

  lcd.i2c.printf("%d:%02d", minutes, seconds);
}

void FStatus::printChallenges()
{
  lcd.i2c.setCursor(0, 1);

  for (int i = 0; i < CHALLENGE_COUNT; i++)
  {
    lcd.i2c.write(i);
    lcd.i2c.write(challengeStatuses[i] ? 7 : 6);
  }
}

void FStatus::updateChallengeStatuses()
{
  for (int i = 0; i < CHALLENGE_COUNT; i++)
  {
    bool newStatus = challenges[i]->getIsDone();
    if (newStatus != challengeStatuses[i])
    {
      challengeStatuses[i] = newStatus;

      if (newStatus == true)
      {
        execChallengeDone();
      }
    }
  }
}

bool FStatus::areAllChallengesDone()
{
  for (bool status : challengeStatuses)
  {
    if (!status)
    {
      return false;
    }
  }

  return true;
}

void FStatus::execChallengeDone()
{
  buzzer.buzz(440, 600);
}

void FStatus::execWin()
{
  hasWon = true;

  disableChallenges();

  lcd.i2c.clear();
  lcd.i2c.home();
  lcd.i2c.print("YOU WIN!!!");

  lcd.i2c.setCursor(0, 1);
  lcd.i2c.printf("SCORE: %d/%d", getTimeRemaining(), SOLVE_TIME);

  buzzer.buzz(440, 600);
  delay(900);
  buzzer.buzz(349, 250);
  delay(300);
  buzzer.buzz(440, 250);
  delay(200);
  buzzer.buzz(523, 900);
}

void FStatus::execLoss()
{
  hasLost = true;

  disableChallenges();

  lcd.i2c.clear();
  lcd.i2c.home();
  lcd.i2c.print("YOU LOSE!!!");

  buzzer.buzz(110, 500);
  delay(750);
  buzzer.buzz(110, 500);
  delay(750);
  buzzer.buzz(110, 500);
  delay(750);
  buzzer.buzz(110, 500);
  delay(750);
  buzzer.buzz(110, 500);
}

void FStatus::disableChallenges()
{
  for (Challenge *challenge : challenges)
  {
    challenge->setIsDone(true);
  }
}
