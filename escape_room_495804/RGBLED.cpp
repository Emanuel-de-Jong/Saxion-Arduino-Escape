#include "RGBLED.h"

RGBLED::RGBLED(uint8_t ledRedPin, uint8_t ledGreenPin, uint8_t ledBluePin) 
: ledRed(ledRedPin),
ledGreen(ledGreenPin),
ledBlue(ledBluePin) {
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
