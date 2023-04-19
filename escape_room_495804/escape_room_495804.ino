#include "globals.h"

#include "FStatus.h"

#include "CTempl.h"
#include "CSafe.h"
#include "CRiddle.h"

FStatus fStatus;

CTempl cTempl;
CSafe cSafe;
CRiddle cRiddle;

void setup() {
  Serial.begin(9600);

  fStatus.setup();
  
  cTempl.setup();
  cSafe.setup();
  cRiddle.setup();
}

void loop() {
  // fStatus.loop();

  cTempl.loop();
  // cSafe.loop();
  cRiddle.loop();
}
