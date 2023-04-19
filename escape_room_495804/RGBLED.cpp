#include "RGBLED.h"

RGBLED::RGBLED(uint8_t ledRedPin, uint8_t ledGreenPin, uint8_t ledBluePin) 
: ledRed(ledRedPin),
ledGreen(ledGreenPin),
ledBlue(ledBluePin),
RED(255, 0, 0),
GREEN(0, 255, 0),
BLUE(0, 0, 255),
YELLOW(255, 255, 0) {
}

void RGBLED::setup() {
  ledRed.setup();
  ledGreen.setup();
  ledBlue.setup();
}

void RGBLED::setColor(RGB rgb) {
  ledRed.setBrightness(rgb.r);
  ledGreen.setBrightness(rgb.g);
  ledBlue.setBrightness(rgb.b);
}
