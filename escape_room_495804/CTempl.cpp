#include "CTempl.h"

CTempl::CTempl(Templ *templ) 
: templ(templ) { 
}

void CTempl::setup() {
  Serial.println("CTempl::setup()");
  
  templ->func1();
}

void CTempl::loop() {
}
