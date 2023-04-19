#ifndef CSIMON_H
#define CSIMON_H

#include <Arduino.h>

#include "globals.h"

#include "Button.h"
#include "RGBLED.h"

#include "CSimonColor.h"

class CSimon {
private:
  Button buttonGreen;
  Button buttonRed;
  Button buttonYellow;
  Button buttonBlue;

  RGBLED rgbLED;

  CSimonColor simonColors[4];
  CSimonColor sequence[4];

  const int SEQUENCE_SIZE = 4;
  int sequenceIndex = 0;

  void createRandomSequence();

public:
  CSimon();
  
  void setup();
  void loop();

  bool isAnyButtonPressed();
};

#endif
