#ifndef CSIMON_H
#define CSIMON_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/hardware/Button.h"
#include "src/hardware/RGBLED.h"

#include "src/challenges/CSimonColor.h"

class CSimon
{
private:
  Button buttonGreen;
  Button buttonRed;
  Button buttonYellow;
  Button buttonBlue;
  Button buttons[4];

  RGBLED rgbLED;

  CSimonColor simonColors[4];
  CSimonColor sequence[4];

  const int SEQUENCE_SIZE = 4;
  int sequenceStage = 1;
  int sequenceIndex = 0;

  const int USER_INPUT_TIME = 3 * 1000;
  int millisSinceUserInput = 0;

  const int COLOR_TIME = 800;
  int millisSinceColorChange = 0;

  bool isUserInputting = false;
  bool isDone = false;

  void blink(RGB color);
  void createRandomSequence();
  bool isAnyButtonPressed();
  bool isButtonPressedValid();

public:
  CSimon();

  void setup();
  void loop();
};

#endif
