#include "Templ.h"

#include "CTempl.h"

#define TEMPL_PIN 0
Templ templ(TEMPL_PIN);

CTempl cTempl(&templ);

void setup() {
  Serial.begin(9600);
  
  cTempl.setup();
}

void loop() {
  cTempl.loop();
}
