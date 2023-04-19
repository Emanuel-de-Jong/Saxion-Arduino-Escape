#ifndef CTEMPL_H
#define CTEMPL_H

#include <Arduino.h>

#include "globals.h"

#include "Templ.h"

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
