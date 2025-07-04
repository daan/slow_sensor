#pragma once
#include <Arduino.h>

#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void temperature_setup() {
  if (!aht.begin()) {
    Serial.println("Could not find AHT10 or AHT20 sensor");
    while (1) delay(10);
  }
}

void temperature_print_data() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print(F("Temperature: "));
  Serial.print(temp.temperature);
  Serial.println(" *C");

  Serial.print(F("Humidity: "));
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");
}
