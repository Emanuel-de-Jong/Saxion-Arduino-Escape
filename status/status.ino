#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int SOLVE_TIME = 5 * 60;

bool challenges[] = {
  false,
  true,
  false,
  false
};

byte uncheckedChar[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B10001,
  B10001,
  B10001,
  B11111
};
byte checkedChar[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte lockChar[] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01110,
  B01110,
  B11111,
  B11111
};
byte riddleChar[] = {
  B00000,
  B00000,
  B00000,
  B11100,
  B10100,
  B11100,
  B10100,
  B11101
};
byte simonChar[] = {
  B00000,
  B00000,
  B00000,
  B11011,
  B11011,
  B00000,
  B11011,
  B11011
};
byte wiringChar[] = {
  B00000,
  B00000,
  B00000,
  B10101,
  B10101,
  B10101,
  B10101,
  B10101
};

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, uncheckedChar);
  lcd.createChar(1, checkedChar);
  lcd.createChar(2, lockChar);
  lcd.createChar(3, riddleChar);
  lcd.createChar(4, simonChar);
  lcd.createChar(5, wiringChar);
}

void loop() {
  lcd.clear();
  lcd.home();

  printTime();
  printChallenges();
  
  delay(1000);
}

void printTime() {
  int timeRemaining = SOLVE_TIME - (millis() / 1000);
  int minutes = timeRemaining / 60;
  int seconds = timeRemaining % 60;
  
  lcd.printf("%d:%02d", minutes, seconds);
}

void printChallenges() {
  lcd.setCursor(0, 1);
  
  lcd.write(2);
  lcd.write(challenges[0] ? 1 : 0);

  lcd.print(" ");
  lcd.write(3);
  lcd.write(challenges[1] ? 1 : 0);
  
  lcd.print(" ");
  lcd.write(4);
  lcd.write(challenges[2] ? 1 : 0);
  
  lcd.print(" ");
  lcd.write(5);
  lcd.write(challenges[3] ? 1 : 0);
}
