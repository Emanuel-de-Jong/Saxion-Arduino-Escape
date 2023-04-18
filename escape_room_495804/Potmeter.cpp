#include "Potmeter.h"

Potmeter::Potmeter(uint8_t pin) 
: pin(pin) {
  pinMode(pin, INPUT);
}

int Potmeter::getValue() {
  return analogRead(pin);
}
