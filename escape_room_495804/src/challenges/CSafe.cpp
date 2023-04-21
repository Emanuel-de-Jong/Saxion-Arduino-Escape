#include "src/challenges/CSafe.h"

CSafe::CSafe(Buzzer &buzzer)
    : buzzer(buzzer), // A reference to the global buzzer
      potmeter(CSAFE_POTMETER_PIN),
      // The ranges of the different stages
      stages{
          CSafeStage(250, 350),
          CSafeStage(625, 675),
          CSafeStage(325, 350),
      },
      CHECK_RATE(100),
      COUNTDOWN_DURATION(1500),
      countdown(COUNTDOWN_DURATION)
{
  setChallengeId(0);
}

void CSafe::setup()
{
  buzzer.setup();
  potmeter.setup();
}

void CSafe::loop()
{
  if (getIsDone())
    return;

  if (millis() - millisSinceCheck <= CHECK_RATE)
    return;
  millisSinceCheck = millis();

  CSafeStage stage = stages[currentStageIndex];

  int potmeterValue = potmeter.getValue();
  if (stage.isInRange(potmeterValue))
  {
    buzzer.buzz(1047, CHECK_RATE + 10);

    countdown -= CHECK_RATE;
    if (countdown <= 0)
    {
      currentStageIndex++;
      if (currentStageIndex + 1 > STAGE_COUNT)
      {
        setIsDone(true);
        return;
      }
    }
  }
  // When the potmeter is not in range but close enough, give a lower buzz to help the user find it
  else
  {
    // There are 2 helper ranges with different buzz frequencies
    if (stage.isInRange(potmeterValue, 50)) // 1-50 units offset
    {
      buzzer.buzz(262, CHECK_RATE + 10);
    }
    else if (stage.isInRange(potmeterValue, 100)) // 51-100 units offset
    {
      buzzer.buzz(65, CHECK_RATE + 10);
    }

    countdown = COUNTDOWN_DURATION;
  }
}
