#include "CTempl.h"

CTempl::CTempl()
    : templ(TEMPL_PIN)
{
}

void CTempl::setup()
{
  Serial.println("CTempl::setup()");

  templ.setup();
  templ.func1();
}

void CTempl::loop()
{
}
