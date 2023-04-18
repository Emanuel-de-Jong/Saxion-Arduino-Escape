#ifndef CTEMPL_H
#define CTEMPL_H

#include <Arduino.h>

#include "Templ.h"

class CTempl {
private:
  Templ *templ;
public:
  CTempl(Templ *templ);
  void setup();
  void loop();
};

#endif
