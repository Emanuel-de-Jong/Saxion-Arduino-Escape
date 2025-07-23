#include "src/functions/FStatus.h"

FStatus::FStatus(Buzzer &buzzer, CSafe *cSafe, CRiddle *cRiddle, CSimon *cSimon, CReaction *cReaction)
    : lcd(FSTATUS_LCD),
      buzzer(buzzer), // A reference to the global buzzer
      SOLVE_TIME(3 * 60),
      // SOLVE_TIME(3), // To test the time running out
      REFRESH_RATE(500),
      // The challenges are put in a list for dynamic code
      challenges{cSafe, cRiddle, cSimon, cReaction}
{
}

void FStatus::setup()
{
  lcd.setup();

  // Add the custom characters to the LCD
  for (int i = 0; i < CHALLENGE_COUNT; i++)
  {
    lcd.i2c.createChar(i, challengeChars[i]);
  }

  lcd.i2c.createChar(6, uncheckedChar);
  lcd.i2c.createChar(7, checkedChar);

  // Turn on backlight for better visibility
  lcd.i2c.backlight();

  // To test the user winnning
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

  // When the time ran out
  if (getTimeRemaining() <= 0)
  {
    execLoss();
    return;
  }

  // Clear the screen and move the cursor back
  lcd.i2c.clear();
  lcd.i2c.home();

  printTime();
  printChallenges();
}

int FStatus::getTimeRemaining()
{
  // The time remaining is the difference between SOLVE_TIME and the time the program has been running (millis())
  return SOLVE_TIME - (millis() / 1000); // Divide by 1000 to convert millis to seconds
}

void FStatus::printTime()
{
  int timeRemaining = getTimeRemaining();
  int minutes = timeRemaining / 60;
  int seconds = timeRemaining % 60;

  // The 02d makes sure the seconds are always 2 digits
  // So 3 seconds would be 03
  lcd.i2c.printf("%d:%02d", minutes, seconds);
}

void FStatus::printChallenges()
{
  // Set cursor to second line
  lcd.i2c.setCursor(0, 1);

  for (int i = 0; i < CHALLENGE_COUNT; i++)
  {
    // Write the custom challenge char
    lcd.i2c.write(i);
    // Write checked or unchecked depending on if the challenge is done
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

      // The challenge is done and wasn't before. So the challenge has just been completed
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
  // Short buzz to tell the user the challenge is done
  buzzer.buzz(440, 600);
}

void FStatus::execWin()
{
  hasWon = true;

  // Disable challenges to minimize the chance of something going wrong
  disableChallenges();

  lcd.i2c.clear();
  lcd.i2c.home();
  lcd.i2c.print("YOU WIN!!!");

  lcd.i2c.setCursor(0, 1);
  // The score is the time remaining. It shows the time they had for comparison
  lcd.i2c.printf("SCORE: %d/%d", getTimeRemaining(), SOLVE_TIME);

  // Short victory melody to tell the user they won
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

  // Disable challenges to minimize the chance of something going wrong
  disableChallenges();

  lcd.i2c.clear();
  lcd.i2c.home();
  lcd.i2c.print("YOU LOSE!!!");

  // Short alarm to tell the user they lost
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
