// All pins defined in a single place
// For an overview and easy customization
// Also makes it easy to see if a pin is accidentaly used twice

#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#define BUZZER_PIN 13

#define CSAFE_POTMETER_PIN A0

#define CRIDDLE_LEDKEY_STROBE_PIN 12
#define CRIDDLE_LEDKEY_CLOCK_PIN 11
#define CRIDDLE_LEDKEY_DIO_PIN 10

#define CSIMON_BUTTON_GREEN_PIN 2
#define CSIMON_BUTTON_RED_PIN 4
#define CSIMON_BUTTON_YELLOW_PIN 7
#define CSIMON_BUTTON_BLUE_PIN 8

#define CSIMON_RGBLED_RED_PIN 5
#define CSIMON_RGBLED_GREEN_PIN 6
#define CSIMON_RGBLED_BLUE_PIN 9

#define CREACTION_LED_1_PIN A1
#define CREACTION_LED_2_PIN A2
#define CREACTION_LED_3_PIN A3

#define CREACTION_BUTTON_PIN 3

#endif
