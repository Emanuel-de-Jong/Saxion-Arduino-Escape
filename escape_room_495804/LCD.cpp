#include "LCD.h"

LCD::LCD()
: i2c(0x27, 16, 2) {
}

void LCD::setup() {
  i2c.init();
}
