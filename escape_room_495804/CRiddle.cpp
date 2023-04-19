#include "CRiddle.h"

CRiddle::CRiddle()
: ledKey(
  CRIDDLE_LEDKEY_STROBE_PIN,
  CRIDDLE_LEDKEY_CLOCK_PIN,
  CRIDDLE_LEDKEY_DIO_PIN
) {
}

void CRiddle::setup() {
  ledKey.setup();
  ledKey.func1();
}

void CRiddle::loop() {
}
