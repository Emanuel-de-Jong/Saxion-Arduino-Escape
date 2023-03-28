#include <string>
#include <TM1638plus.h>

#define TM_STROBE 4
#define TM_CLOCK 6
#define TM_DIO 7

TM1638plus tm(TM_STROBE, TM_CLOCK, TM_DIO);

const int NUM_1 = 5;
const int NUM_2 = 3;

const int NUM_1_PRESSES = 2;
const int NUM_2_PRESSES = 5;

void setup() {
  tm.displayBegin();
  std::string leftDisplayText = std::to_string(NUM_1) + std::to_string(NUM_1_PRESSES) + std::to_string(NUM_2) + std::to_string(NUM_2_PRESSES);
  tm.displayText(leftDisplayText.c_str());
}

void loop() {
  // for (uint8_t i=0; i<255; i++) {
  //   tm.setLEDs((i << 8) | 0);
  //   tm.displayIntNum(i, false, TMAlignTextRight);
  //   tm.displayHex(0, i >> 4);
  //   tm.displayHex(1, i);
  //   delay(500);
  // }
}