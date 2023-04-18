#include "globals.h"

#include "CTempl.h"
#include "CLock.h"

CTempl cTempl;
CLock cLock;

void setup() {
  Serial.begin(9600);
  
  cTempl.setup();
  cLock.setup();
}

void loop() {
  cTempl.loop();
  cLock.loop();
}
