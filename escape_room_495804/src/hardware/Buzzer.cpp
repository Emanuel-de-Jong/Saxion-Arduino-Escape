#include "src/hardware/Buzzer.h"

Buzzer::Buzzer(uint8_t pin)
    : pin(pin)
{
}

void Buzzer::setup()
{
  pinMode(pin, OUTPUT);
  noTone(pin);
}

void Buzzer::buzz(int frequency, int duration)
{
  tone(pin, frequency, duration);
}
