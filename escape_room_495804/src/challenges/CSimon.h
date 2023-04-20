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

  const int BUTTON_COOLDOWN_TIME = 1000;
  int millisSinceButtonCooldown = 0;

  const int COLOR_TIME = 500;
  const int BLANK_TIME = 150;
  int millisSinceColorChange = 0;

  const int COLOR_SEQUENCE_RESTART_TIME = 2500;
  int millisSinceColorSequenceRestart = 0;

  bool isButtonPressed = false;
  bool isUserInputting = false;
  bool isStageChanged = false;
  bool isDone = false;

  void checkButtonInput();
  void checkButtonInputValidity();
  void showSequence();

  void createRandomSequence();
  bool isAnyButtonPressed();
  bool isButtonPressedValid();

public:
  CSimon();

  void setup();
  void loop();
};

#endif
