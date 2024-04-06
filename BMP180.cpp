#include "BMP180.h"
#include <BMP180I2C.h>

#define BMP180_ADDRESS 0x77
BMP180I2C bmp180(BMP180_ADDRESS);

float BMP180::getTemperatureBMP180()
{
  bmp180.measureTemperature();
  do
  {
    delay(100);
  } while (!bmp180.hasValue());
  return(bmp180.getTemperature()); 
}

float BMP180::getPressureBMP180()
{
  bmp180.measurePressure();
  do
  {
    delay(100);
  } while (!bmp180.hasValue());
  return bmp180.getPressure() / 100;
}

void BMP180::BMPSetUp()
{
  bmp180.begin();
  bmp180.resetToDefaults();
  bmp180.setSamplingMode(BMP180MI::MODE_UHR);    
}
