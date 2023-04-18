#include "CLock.h"

CLock::CLock()
: button(CLOCK_BUTTON_PIN) {
}

void CLock::setup() {
}

void CLock::loop() {
  if (button.isPressed()) {
    Serial.println("pressed");
  } else {
    Serial.println("not pressed");
  }
}
