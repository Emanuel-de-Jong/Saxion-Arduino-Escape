#include "globals.h"

#include "CTempl.h"

CTempl cTempl;

void setup() {
  Serial.begin(9600);
  
  cTempl.setup();
}

void loop() {
  cTempl.loop();
}
