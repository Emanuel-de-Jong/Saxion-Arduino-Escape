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
),
simonColors{
  CSimonColor(buttonGreen, rgbLED.GREEN),
  CSimonColor(buttonRed, rgbLED.RED)
} {
}

void CSimon::setup() {
  buttonGreen.setup();
  buttonRed.setup();
  buttonYellow.setup();
  buttonBlue.setup();

  rgbLED.setup();

  rgbLED.setColor(simonColors[0].rgb);
}

void CSimon::loop() {
  if (simonColors[0].button.isPressed()) {
    Serial.println("Green");
  }
  
  delay(100);
}
