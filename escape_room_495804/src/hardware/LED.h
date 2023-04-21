#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED
{
private:
  uint8_t pin;

public:
  LED(uint8_t pin);

  void setup();

  void turnOn();
  void turnOff();
  void setBrightness(int brightness);
  int getPin() const;

  // Compares 2 LEDs by their pin number
  bool operator==(const LED &led) const;
};

#endif
