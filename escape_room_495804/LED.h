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
};

#endif
