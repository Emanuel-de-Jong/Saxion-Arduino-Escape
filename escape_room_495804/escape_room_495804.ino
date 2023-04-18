#include "globals.h"

#include "FStatus.h"

#include "CTempl.h"
#include "CSafe.h"

FStatus fStatus;

CTempl cTempl;
CSafe cSafe;

void setup() {
  Serial.begin(9600);

  fStatus.setup();
  
  cTempl.setup();
  cSafe.setup();
}

void loop() {
  fStatus.loop();

  cTempl.loop();
  // cSafe.loop();
}
