#include "CSafe.h"

CSafe::CSafe()
: buzzer(CSAFE_BUZZER_PIN), potmeter(CSAFE_POTMETER_PIN) {
}

void CSafe::setup() {
}

void CSafe::loop() {
  delay(1000);
  buzzer.buzz(500);
  Serial.println(potmeter.getValue());
}
