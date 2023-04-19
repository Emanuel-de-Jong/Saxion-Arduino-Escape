#include "Potmeter.h"

Potmeter::Potmeter(uint8_t pin) 
: pin(pin) {
}

void Potmeter::setup() {
  pinMode(pin, INPUT);
}

int Potmeter::getValue() {
  return analogRead(pin);
}
