#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    uint8_t pin = -1;

  public:
    Button();
    Button(uint8_t pin);

    void setup();

    bool isPressed();
    int getPin();
};

#endif
