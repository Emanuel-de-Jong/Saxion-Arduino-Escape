#include "globals.h"

#include "FStatus.h"

#include "CSafe.h"
#include "CRiddle.h"
#include "CSimon.h"

FStatus fStatus;

CSafe cSafe;
CRiddle cRiddle;
CSimon cSimon;

void setup() {
  Serial.begin(9600);

  fStatus.setup();
  
  cSafe.setup();
  cRiddle.setup();
  cSimon.setup();
}

void loop() {
  // fStatus.loop();

  // cSafe.loop();
  // cRiddle.loop();
  cSimon.loop();
}
