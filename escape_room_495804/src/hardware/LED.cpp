#include "src/hardware/LED.h"

LED::LED(uint8_t pin)
    : pin(pin)
{
}

void LED::setup()
{
  pinMode(pin, OUTPUT);
}

void LED::turnOn()
{
  analogWrite(pin, 255);
}

void LED::turnOff()
{
  analogWrite(pin, 0);
}

void LED::setBrightness(int brightness)
{
  analogWrite(pin, brightness);
}

int LED::getPin() const
{
  return pin;
}

// Compares 2 LEDs by their pin number
bool LED::operator==(const LED &led) const
{
  return getPin() == led.getPin();
}
