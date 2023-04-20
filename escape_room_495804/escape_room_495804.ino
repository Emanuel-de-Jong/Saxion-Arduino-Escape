#include "src/globals.h"

#include "src/functions/FStatus.h"

#include "src/challenges/CSafe.h"
#include "src/challenges/CRiddle.h"
#include "src/challenges/CSimon.h"
#include "src/challenges/CReaction.h"

FStatus fStatus;

CSafe cSafe;
CRiddle cRiddle;
CSimon cSimon;
CReaction cReaction;

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
  // fStatus.loop();

  // cSafe.loop();
  // cRiddle.loop();
  cSimon.loop();
  // cReaction.loop();
}
