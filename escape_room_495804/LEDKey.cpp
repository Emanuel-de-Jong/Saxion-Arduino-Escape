#include "LEDKey.h"

LEDKey::LEDKey(uint8_t strobePin, uint8_t clockPin, uint8_t dioPin) 
: tm(strobePin, clockPin, dioPin) {
}

void LEDKey::setup() {
  tm.displayBegin();
}

void LEDKey::func1() {
  Serial.println("LEDKey::func1()");
}
