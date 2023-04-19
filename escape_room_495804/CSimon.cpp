#include "CSimon.h"

CSimon::CSimon()
: buttonGreen(CSIMON_BUTTON_GREEN_PIN),
buttonRed(CSIMON_BUTTON_RED_PIN),
buttonYellow(CSIMON_BUTTON_YELLOW_PIN),
buttonBlue(CSIMON_BUTTON_BLUE_PIN),
rgbLED(
  CSIMON_RGBLED_RED_PIN,
  CSIMON_RGBLED_GREEN_PIN,
  CSIMON_RGBLED_BLUE_PIN
) {
}

void CSimon::setup() {
  buttonGreen.setup();
  buttonRed.setup();
  buttonYellow.setup();
  buttonBlue.setup();

  rgbLED.setup();

  rgbLED.setColor(rgbLED.YELLOW);
}

void CSimon::loop() {
  if (buttonGreen.isPressed()) {
    Serial.println("Green");
  }
  if (buttonRed.isPressed()) {
    Serial.println("Red");
  }
  if (buttonYellow.isPressed()) {
    Serial.println("Yellow");
  }
  if (buttonBlue.isPressed()) {
    Serial.println("Blue");
  }
  
  delay(100);
}
