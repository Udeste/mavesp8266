#include "mavesp8266.h"
#include "mavesp8266_parameters.h"
#include "mavesp8266_neopixel.h"

Adafruit_NeoPixel STATUS_LEDS  = Adafruit_NeoPixel(0, -1, NEO_GRB + NEO_KHZ800);


MavESP8266Neopixel::MavESP8266Neopixel() {}

void
MavESP8266Neopixel::init() {
  uint8_t ledsMode = getWorld()->getParameters()->getLedsMode();

  STATUS_LEDS.setPin(getWorld()->getParameters()->getLedsPin());
  STATUS_LEDS.updateLength(getWorld()->getParameters()->getLedsCount());
  STATUS_LEDS.begin();


  switch (ledsMode) {
    case 0:
      offMode();
      break;
    case 2:
      i2cMode();
      break;
    case 1:
    default:
      staticColorMode();
      break;
  }
}

void
MavESP8266Neopixel::offMode() {
  STATUS_LEDS.fill(STATUS_LEDS.Color(0, 0, 0), 0, STATUS_LEDS.numPixels());
  STATUS_LEDS.show();
  STATUS_LEDS.clear();
}

void
MavESP8266Neopixel::staticColorMode() {
  uint8_t red = getWorld()->getParameters()->getLedsRed();
  uint8_t green = getWorld()->getParameters()->getLedsGreen();
  uint8_t blue = getWorld()->getParameters()->getLedsBlue();
  STATUS_LEDS.fill(STATUS_LEDS.Color(red, green, blue), 0, STATUS_LEDS.numPixels());
  STATUS_LEDS.show();
}

void
MavESP8266Neopixel::i2cMode() {
// TODO
}