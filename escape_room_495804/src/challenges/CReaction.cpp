#include "src/challenges/CReaction.h"

CReaction::CReaction()
    : led1(CREACTION_LED_1_PIN),
    led2(CREACTION_LED_2_PIN),
    led3(CREACTION_LED_3_PIN),
    button(CREACTION_BUTTON_PIN),
    leds{led1, led2, led3},
    SPEED(500)
{
}

void CReaction::setup()
{
  for (LED led : leds) {
    led.setup();
  }

  button.setup();
}

void CReaction::loop()
{
  if (button.isPressed()) {
    Serial.println("asd");
  }

  if (millis() - millisSinceLEDOn > SPEED) {
    millisSinceLEDOn = millis();

    turnAllLEDsOff();
    leds[ledIndex].turnOn();

    if (isLeftToRight) {
      ledIndex++;
      if (ledIndex + 1 > LED_COUNT) {
        ledIndex = ledIndex - 2;
        isLeftToRight = false;
      }

    } else {
      ledIndex--;
      if (ledIndex == -1) {
        ledIndex = 1;
        isLeftToRight = true;
      }
    }
  }

}

void CReaction::turnAllLEDsOff() {
  for (LED led : leds) {
    led.turnOff();
  }
}
