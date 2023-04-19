#ifndef TEMPL_H
#define TEMPL_H

#include <Arduino.h>

class Templ {
  private:
    uint8_t pin;

  public:
    Templ(uint8_t pin);

    void setup();

    void func1();
};

#endif
