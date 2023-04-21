// The root of the project
// The challenges, functions and global hardware are created, initialized and looped here

#include "src/globals.h"

#include "src/functions/FStatus.h"

#include "src/challenges/CSafe.h"
#include "src/challenges/CRiddle.h"
#include "src/challenges/CSimon.h"
#include "src/challenges/CReaction.h"

#include "src/hardware/Buzzer.h"

// The buzzer is used by multiple components, so it's defined globally here
Buzzer buzzer(BUZZER_PIN);

CSafe cSafe(buzzer);
CRiddle cRiddle;
CSimon cSimon;
CReaction cReaction;

FStatus fStatus(buzzer, &cSafe, &cRiddle, &cSimon, &cReaction);

void setup()
{
  Serial.begin(9600);

  fStatus.setup();

  cSafe.setup();
  cRiddle.setup();
  cSimon.setup();
  cReaction.setup();
}

void loop()
{
  fStatus.loop();

  cSafe.loop();
  cRiddle.loop();
  cSimon.loop();
  cReaction.loop();
}
