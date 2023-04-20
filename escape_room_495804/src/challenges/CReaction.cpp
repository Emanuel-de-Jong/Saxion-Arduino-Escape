#include "src/challenges/CReaction.h"

CReaction::CReaction()
    : led1(CREACTION_LED_1_PIN),
    led2(CREACTION_LED_2_PIN),
    led3(CREACTION_LED_3_PIN)
{
}

void CReaction::setup()
{
  led1.setup();
  led2.setup();
  led3.setup();
}

void CReaction::loop()
{
  led1.turnOn();
  led2.turnOn();
  led3.turnOn();
  delay(500);

  led1.turnOff();
  led2.turnOff();
  led3.turnOff();
  delay(500);
}
