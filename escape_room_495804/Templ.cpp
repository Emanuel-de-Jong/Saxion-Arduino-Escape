#include "Templ.h"

Templ::Templ(uint8_t pin) 
: pin(pin) {
  pinMode(pin, OUTPUT);
}

void Templ::func1() {
  Serial.println("Templ::func1()");
}
