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

// https://www.st.com/resource/en/design_tip/dt0140-tilt-computation-using-accelerometer-data-for-inclinometer-applications-stmicroelectronics.pdf
// α = arctan2(AccXY, AccZ), arctan2 output range is -180 to +180 degrees


float calculate_tilt(float ax, float ay, float az) {
  sensors_event_t accel, gyro, temp;
  lsm6ds3trc.getEvent(&accel, &gyro, &temp);

  double xy_magnitude = sqrt(ax * ax + ay * ay);
  // Use atan2 to calculate the angle in radians
  // atan2(y, x) returns the angle whose tangent is the quotient of the two specified numbers.
  // Here we use xy_magnitude as the first argument and accel.acceleration.z as the second argument.
  // This gives us the angle in radians between the XY plane and the Z axis.
  double angle_radians = atan2(xy_magnitude, az);

  return (float)(angle_radians * 180.0 / PI); // Convert radians to degrees

}


void tilt_print_data() {
    
    sensors_event_t accel, gyro, temp;
    lsm6ds3trc.getEvent(&accel, &gyro, &temp);
    Serial.print("Temperature ");
  Serial.print(temp.temperature);
  Serial.println(" deg C");

float tilt_angle = calculate_tilt(accel.acceleration.x, accel.acceleration.y, accel.acceleration.z);
    Serial.print("Tilt angle: ");
  Serial.print(tilt_angle);
  Serial.println(" degrees");   


//   /* Display the results (acceleration is measured in m/s^2) */
//   Serial.print("Accel X: ");
//   Serial.print(accel.acceleration.x);
//   Serial.print(" \tY: ");
//   Serial.print(accel.acceleration.y);
//   Serial.print(" \tZ: ");
//   Serial.print(accel.acceleration.z);
//   Serial.println(" m/s^2 ");

//   /* Display the results (rotation is measured in rad/s) */
//   Serial.print("Gyro X: ");
//   Serial.print(gyro.gyro.x);
//   Serial.print(" \tY: ");
//   Serial.print(gyro.gyro.y);
//   Serial.print(" \tZ: ");
//   Serial.print(gyro.gyro.z);
//   Serial.println(" radians/s ");
}

