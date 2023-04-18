#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin) 
: pin(pin) {
  pinMode(pin, OUTPUT);
}

void Buzzer::buzz(int duration) {
  tone(pin, 262, duration);
}
