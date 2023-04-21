#ifndef CSIMON_H
#define CSIMON_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/challenges/Challenge.h"

#include "src/hardware/Button.h"
#include "src/hardware/RGBLED.h"

#include "src/challenges/CSimonColor.h"

class CSimon : public Challenge
{
private:
  Button buttonGreen;
  Button buttonRed;
  Button buttonYellow;
  Button buttonBlue;
  Button buttons[4];

  RGBLED rgbLED;

  CSimonColor simonColors[4];
  CSimonColor sequence[6];

  const int SEQUENCE_SIZE = 6;
  const int SEQUENCE_STARTING_STAGE;
  int sequenceStage = 0;
  int sequenceIndex = 0;

  const int USER_INPUT_TIME;
  int millisSinceUserInput = 0;

  const int BUTTON_COOLDOWN_TIME;
  int millisSinceButtonCooldown = 0;

  const int COLOR_TIME;
  const int BLANK_TIME;
  int millisSinceColorChange = 0;

  const int COLOR_SEQUENCE_RESTART_TIME;
  int millisSinceColorSequenceRestart = 0;

  bool isButtonPressed = false;
  bool isUserInputting = false;
  bool isStageChanged = false;

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
