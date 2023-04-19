#include "Button.h"

Button::Button() {}

Button::Button(uint8_t pin) 
: pin(pin) {
}

void Button::setup() {
  pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed() {
  return !digitalRead(pin);
}

int Button::getPin() const {
  return pin;
}

bool Button::operator==(const Button& button) const {
  return getPin() == button.getPin();
}
