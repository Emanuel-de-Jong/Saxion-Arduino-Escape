#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>

#include <RGB.h>

#include <LED.h>

class RGBLED {
  private:
    LED ledRed;
    LED ledGreen;
    LED ledBlue;

    RGB &currentRGB;

  public:
    RGB BLACK;
    RGB WHITE;
    RGB RED;
    RGB GREEN;
    RGB BLUE;
    RGB YELLOW;

    RGBLED(uint8_t ledRedPin, uint8_t ledGreenPin, uint8_t ledBluePin);

    void setup();

    void turnOn();
    void turnOff();
    void setColor(RGB rgb);
};

#endif
