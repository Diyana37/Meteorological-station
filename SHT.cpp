#include "SHT.h"
#include <SHT21.h>

//#define SHT21_ADDRESS 0x40
//BMP180I2C bmp180(BMP180_ADDRESS);
SHT21 sht21;

float SHT::getTemperatureSHT()
{
  return sht21.getTemperature(); 
}

float SHT::getHumiditySHT()
{
  return sht21.getHumidity();
}
