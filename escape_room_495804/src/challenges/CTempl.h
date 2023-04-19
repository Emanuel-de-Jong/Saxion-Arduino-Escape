#ifndef CTEMPL_H
#define CTEMPL_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/hardware/Templ.h"

class CTempl
{
private:
  Templ templ;

public:
  CTempl();

  void setup();
  void loop();
};

#endif
