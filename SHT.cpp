#include "SHT.h"
#include <SHT21.h>

SHT21 sht21;

float SHT::getTemperatureSHT()
{
  return sht21.getTemperature(); 
}

float SHT::getHumiditySHT()
{
  return sht21.getHumidity();
}
