#include "src/functions/FStatus.h"

FStatus::FStatus()
    : SOLVE_TIME(5 * 60),
      REFRESH_RATE(500)
{
}

void FStatus::setup()
{
  lcd.setup();

  lcd.i2c.createChar(0, uncheckedChar);
  lcd.i2c.createChar(1, checkedChar);
  lcd.i2c.createChar(2, lockChar);
  lcd.i2c.createChar(3, riddleChar);
  lcd.i2c.createChar(4, simonChar);
  lcd.i2c.createChar(5, wiringChar);

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

  lcd.i2c.write(2);
  lcd.i2c.write(challenges[0] ? 1 : 0);

  lcd.i2c.print(" ");
  lcd.i2c.write(3);
  lcd.i2c.write(challenges[1] ? 1 : 0);

  lcd.i2c.print(" ");
  lcd.i2c.write(4);
  lcd.i2c.write(challenges[2] ? 1 : 0);

  lcd.i2c.print(" ");
  lcd.i2c.write(5);
  lcd.i2c.write(challenges[3] ? 1 : 0);
}
