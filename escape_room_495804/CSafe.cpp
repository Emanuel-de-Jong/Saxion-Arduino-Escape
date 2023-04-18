#include "CSafe.h"

CSafe::CSafe()
: buzzer(CSAFE_BUZZER_PIN),
potmeter(CSAFE_POTMETER_PIN),
stages{
    CSafeStage(250, 350),
    CSafeStage(625, 675),
    CSafeStage(325, 350),
} {
}

void CSafe::setup() {
}

void CSafe::loop() {
  delay(1000);
  buzzer.buzz(500);
  Serial.println(potmeter.getValue());
}
