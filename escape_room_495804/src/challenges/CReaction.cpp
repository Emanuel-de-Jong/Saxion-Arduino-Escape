#include "src/challenges/CReaction.h"

CReaction::CReaction()
    : CHALLENGE_ID(3),
      led1(CREACTION_LED_1_PIN),
      led2(CREACTION_LED_2_PIN),
      led3(CREACTION_LED_3_PIN),
      ledToHit(led2),
      button(CREACTION_BUTTON_PIN),
      leds{led1, led2, led3},
      SPEED(500)
{
}

void CReaction::setup()
{
  for (LED led : leds)
  {
    led.setup();
  }

  button.setup();
}

void CReaction::loop()
{
  if (isDone)
    return;

  if (button.isPressed())
  {
    if (leds[ledIndex] == ledToHit)
    {
      isDone = true;

      delay(1000);
      ledToHit.turnOff();

      return;
    }
    else
    {
      for (int i = 0; i < 5; i++)
      {
        leds[ledIndex].turnOff();
        delay(100);

        leds[ledIndex].turnOn();
        delay(100);
      }
    }
  }

  if (millis() - millisSinceLEDOn > SPEED)
  {
    millisSinceLEDOn = millis();

    if (isLeftToRight)
    {
      ledIndex++;
      if (ledIndex + 1 > LED_COUNT)
      {
        ledIndex = ledIndex - 2;
        isLeftToRight = false;
      }
    }
    else
    {
      ledIndex--;
      if (ledIndex == -1)
      {
        ledIndex = 1;
        isLeftToRight = true;
      }
    }

    turnAllLEDsOff();
    leds[ledIndex].turnOn();
  }
}

void CReaction::turnAllLEDsOff()
{
  for (LED led : leds)
  {
    led.turnOff();
  }
}

int CReaction::getChallengeId() {
  return CHALLENGE_ID;
}
