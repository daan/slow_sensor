#pragma once

#include <Arduino.h>
#include <Adafruit_LSM6DS3TRC.h>

Adafruit_LSM6DS3TRC lsm6ds3trc;

void tilt_setup() {
  if (!lsm6ds3trc.begin_I2C()) {
    Serial.println("No LSM6DS3TRC sensor found");
    while (1) delay(10);
  }
}

void tilt_print_data() {
    sensors_event_t accel, gyro, temp;
    lsm6ds3trc.getEvent(&accel, &gyro, &temp);
    Serial.print("Temperature ");
  Serial.print(temp.temperature);
  Serial.println(" deg C");

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("Accel X: ");
  Serial.print(accel.acceleration.x);
  Serial.print(" \tY: ");
  Serial.print(accel.acceleration.y);
  Serial.print(" \tZ: ");
  Serial.print(accel.acceleration.z);
  Serial.println(" m/s^2 ");

  /* Display the results (rotation is measured in rad/s) */
  Serial.print("Gyro X: ");
  Serial.print(gyro.gyro.x);
  Serial.print(" \tY: ");
  Serial.print(gyro.gyro.y);
  Serial.print(" \tZ: ");
  Serial.print(gyro.gyro.z);
  Serial.println(" radians/s ");
}

