# slow_sensor

first prototype is based on the xiao esp32s3 sense with breakout boards connected with i2c

| sensor | i2c address | library |
| ------ | ----------- | ------- |
| [realtime clock DS3231](https://www.adafruit.com/product/5188) | 0x68 | [rtclib](https://github.com/adafruit/RTClib) |
| [light sensor TSL2491](https://www.adafruit.com/product/1980) | 0x29 | TSL2591 Library |
| [Temperature and Humidity AHT20](https://www.adafruit.com/product/4566) | 0x29 | Adafruit AHTX0 |
| [Tilt LSM6DS3](https://www.adafruit.com/product/4503) | 0x6A | Adafruit_LSM6DS |
| [Moisture ATSAMD10](https://www.adafruit.com/product/4026) |  0x36 | Adafruit_Seesaw |

