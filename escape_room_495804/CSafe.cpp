#include "CSafe.h"

CSafe::CSafe()
: button(CSAFE_BUTTON_PIN) {
}

void CSafe::setup() {
}

void CSafe::loop() {
  if (button.isPressed()) {
    Serial.println("pressed");
  } else {
    Serial.println("not pressed");
  }
}
