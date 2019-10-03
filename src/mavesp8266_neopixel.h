#ifndef MAVESP8266_NEOPIXEL_H
#define MAVESP8266_NEOPIXEL_H


#include <Adafruit_NeoPixel.h>


class MavESP8266Neopixel {
  public:
    MavESP8266Neopixel();
    void init();
    void offMode();
    void staticColorMode();
    void i2cMode();
};


#endif