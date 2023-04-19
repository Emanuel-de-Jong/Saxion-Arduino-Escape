#include "Button.h"

Button::Button(uint8_t pin) 
: pin(pin) {
}

void Button::setup() {
  pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed() {
  return !digitalRead(pin);
}
