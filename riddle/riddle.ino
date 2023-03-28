#include <string>
#include <TM1638plus.h>

#define TM_STROBE 4
#define TM_CLOCK 6
#define TM_DIO 7

TM1638plus tm(TM_STROBE, TM_CLOCK, TM_DIO);

const int NUM_1 = 5;
const int NUM_2 = 8;

const int BTN_1_PRESSES = 2;
const int BTN_2_PRESSES = 5;

int leftDisplay = std::stoi(
  std::to_string(NUM_1) +
  std::to_string(BTN_1_PRESSES) +
  std::to_string(NUM_2) +
  std::to_string(BTN_2_PRESSES)
);

int stage = 0;

int lastBtn = -1;
int consecutiveBtnPressed = 1;

void setup() {
  Serial.begin(9600);
  
  tm.displayBegin();
  tm.displayIntNum(leftDisplay, false, TMAlignTextLeft);

  tm.setLEDs(0b1111111100000000);
}

void loop() {
  // for (int i=0; i<8; i++) {
  //   Serial.print(i);
  //   Serial.print(":");
  //   Serial.print(isButtonPressed(i));
  //   Serial.print(", ");
  // }
  // Serial.println();

  int btn = getPressedBtn();
  if (btn == -1) return;

  if (btn == lastBtn) {
    consecutiveBtnPressed++;    
  } else {
    lastBtn = btn;
    consecutiveBtnPressed = 1;
  }

  tm.DisplayDecNumNibble(leftDisplay, consecutiveBtnPressed);

  int num = stage == 0 ? NUM_1 : NUM_2;
  int btnPresses = stage == 0 ? BTN_1_PRESSES : BTN_2_PRESSES;
  if (consecutiveBtnPressed == btnPresses && btn == num - 1) {
    consecutiveBtnPressed = 0;
    tm.DisplayDecNumNibble(leftDisplay, consecutiveBtnPressed);
    
    stage++;

    if (stage == 1) { 
      tm.setLEDs(0b1111000000000000);      
    } else {
      tm.setLEDs(0b0000000000000000);        
    }
  }
  
  delay(250);
}

int getPressedBtn() {
  uint8_t buttons = tm.readButtons();
  for (int i = 0; i < 8; i++) {
    if ((buttons >> i)  & 0x01) {
      return i;
    }
  }
  
  return -1;
}
  