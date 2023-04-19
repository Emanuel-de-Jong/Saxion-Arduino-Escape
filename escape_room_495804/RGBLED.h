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

  public:
    const RGB RED(255, 0, 0);
    const RGB GREEN(0, 255, 0);
    const RGB BLUE(0, 0, 255);
    const RGB YELLOW(255, 255, 0);

    RGBLED(uint8_t ledRedPin, uint8_t ledGreenPin, uint8_t ledBluePin);

    void setup();

    void setColor(RGB rgb);
};

#endif
