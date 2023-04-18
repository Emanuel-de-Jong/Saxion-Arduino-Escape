#include "FStatus.h"

FStatus::FStatus()
: SOLVE_TIME(5 * 60) {
}

void FStatus::setup() {
  lcd.i2c.createChar(0, uncheckedChar);
  lcd.i2c.createChar(1, checkedChar);
  lcd.i2c.createChar(2, lockChar);
  lcd.i2c.createChar(3, riddleChar);
  lcd.i2c.createChar(4, simonChar);
  lcd.i2c.createChar(5, wiringChar);

  lcd.i2c.backlight();
}

void FStatus::loop() {
  lcd.i2c.clear();
  lcd.i2c.home();
  lcd.i2c.print("asd");
  delay(1000);
}
