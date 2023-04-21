// Repeat the color sequence in the right order as it increases in complexity

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
  // A list of the buttons above for dynamic loops
  Button buttons[4];

  RGBLED rgbLED;

  // The 4 possible button - color combinations
  CSimonColor simonColors[4];
  // The sequence to display and press
  CSimonColor sequence[6];

  const int SEQUENCE_SIZE = 6;
  const int SEQUENCE_STARTING_STAGE;
  // Each time the user righly presses part of the sequence, the stage goes up by 1
  // And the user has to press the sequence again with 1 color added to the end
  int sequenceStage = 0;
  // The index keeps track of the color to be pressed/displayed and is reset on every stage change
  int sequenceIndex = 0;

  // Time in milliseconds the user has to press the next button. Is reset on a button press
  // Once the time is up, it is assumed the user forgot the sequence, so it's shown again
  const int USER_INPUT_TIME;
  int millisSinceUserInput = 0;

  const int BUTTON_COOLDOWN_TIME;
  int millisSinceButtonCooldown = 0;

  // Duration that the LED is on
  const int COLOR_TIME;
  // Duration that the LED is off before showing the next color
  const int BLANK_TIME;
  int millisSinceColorChange = 0;

  // Duration before the sequence is shown again
  // Without this, the start and end of the sequence would be unclear to the user
  const int COLOR_SEQUENCE_RESTART_TIME;
  int millisSinceColorSequenceRestart = 0;

  bool isButtonPressed = false;
  // Related to USER_INPUT_TIME
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
