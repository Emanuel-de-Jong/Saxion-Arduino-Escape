#include "globals.h"

#include "CTempl.h"
#include "CSafe.h"

CTempl cTempl;
CSafe cSafe;

void setup() {
  Serial.begin(9600);
  
  cTempl.setup();
  cSafe.setup();
}

void loop() {
  cTempl.loop();
  cSafe.loop();
}
