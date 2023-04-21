#include "src/challenges/CReaction.h"

CReaction::CReaction()
    : led1(CREACTION_LED_1_PIN),
      led2(CREACTION_LED_2_PIN),
      led3(CREACTION_LED_3_PIN),
      ledToHit(led2),
      button(CREACTION_BUTTON_PIN),
      leds{led1, led2, led3},
      SPEED(200)
{
  setChallengeId(3);
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
  if (getIsDone())
    return;

  if (button.isPressed())
  {
    // Checks if the LED that was on when the user pressed the button, was the green LED
    if (leds[ledIndex] == ledToHit)
    {
      setIsDone(true);

      // Delay for feedback that the user really pressed the green LED
      delay(1000);
      ledToHit.turnOff();

      return;
    }
    else
    {
      // Blink the wrongly pressed red LED to indicate what went wrong
      for (int i = 0; i < 5; i++)
      {
        leds[ledIndex].turnOff();
        delay(100);

        leds[ledIndex].turnOn();
        delay(100);
      }
    }
  }

  // Executes every SPEED milliseconds
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

    // Lazy way to turn the last LED off
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
