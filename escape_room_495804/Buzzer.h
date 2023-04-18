#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
  private:
    uint8_t pin;

  public:
    Buzzer(uint8_t pin);

    void buzz(int frequency, int duration);
};

#endif
