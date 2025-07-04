# slow_sensor




first prototype is built with a xiao esp32s3 sense with breakout boards connected with i2c


| sensor | i2c address | library |
| ------ | ----------- | ------- |
| (https://www.adafruit.com/product/5188)[realtime clock DS3231] | 0x68 | (https://github.com/adafruit/RTClib)[rtclib] |
| (https://www.adafruit.com/product/1980)[light sensor TSL2491] | 0x29 | TSL2591 Library |
| (https://www.adafruit.com/product/4566)[Temperature and Humidity AHT20] | 0x29 | Adafruit AHTX0 |
| (https://www.adafruit.com/product/4503)[Tilt LSM6DS3] | 0x6A | Adafruit_LSM6DS |
| (https://www.adafruit.com/product/4026)[Moisture ATSAMD10] |  0x36 | Adafruit_Seesaw |

