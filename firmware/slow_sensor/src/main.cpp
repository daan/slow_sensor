#include <Arduino.h>
#include <SPI.h>


#include "rtc.h"
#include "light.h"
#include "temperature.h"
#include "tilt.h"

const int ledPin = LED_BUILTIN; // Use the built-in LED pin

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  rtc_setup();
  light_setup();
  temperature_setup();
  tilt_setup();
  // Wire.begin();
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(2000);
  // Serial.println("Blinking LED");
  // i2c_scanner();
  rtc_print_datetime();
  light_print_luminosity();
  temperature_print_data();
  tilt_print_data();
  Serial.println();
  Serial.println();
}

