#include "LED.h"

LED::LED(uint8_t pin) 
: pin(pin) {
}

void LED::setup() {
  pinMode(pin, OUTPUT);
}

void LED::turnOn() {
  digitalWrite(pin, HIGH);
}

void LED::turnOff() {
  digitalWrite(pin, LOW);
}

void LED::setBrightness(int brightness) {
  analogWrite(pin, brightness);
}
