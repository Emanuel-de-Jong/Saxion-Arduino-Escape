#ifndef CSIMON_H
#define CSIMON_H

#include <Arduino.h>

#include "src/globals.h"

#include "src/functions/FStatus.h"

#include "src/hardware/Button.h"
#include "src/hardware/RGBLED.h"

#include "src/challenges/CSimonColor.h"

extern FStatus fStatus;

class CSimon
{
private:
  const int CHALLENGE_ID;

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

  int getChallengeId();
};

#endif
