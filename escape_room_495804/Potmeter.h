#ifndef POTMETER_H
#define POTMETER_H

#include <Arduino.h>

class Potmeter {
  private:
    uint8_t pin;

  public:
    Potmeter(uint8_t pin);

    int getValue();
};

#endif
