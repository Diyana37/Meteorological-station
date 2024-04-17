#include <Wire.h>
#include "BMP180.h"
#include <BMP180I2C.h>
#include <SHT21.h>  
#include "SHT.h"
#include <UTFT.h>
#include "LCD.h"
#include "Coordinates.h"
#include "Average.h"

SHT sht; 
BMP180 bmp;
LCD lcd;
Average average;
float temp;
float humidity;
float pressure;

const int arrSize = 20;
float tempArr[arrSize];
float humArr[arrSize];
float pressArr[arrSize];
int counter = 0;

void setup() 
{
    Serial.begin(115200);
    Wire.begin();
    bmp.BMPSetUp();
    lcd.LCDSetUp();
    lcd.Draw();

    temp = sht.getTemperatureSHT();
    humidity = sht.getHumiditySHT();
    pressure = bmp.getPressureBMP180();
    for(int i = 0; i < arrSize; i++)
    {
      tempArr[i] = temp;
      humArr[i] = humidity;
      pressArr[i] = pressure;
    }
}
  
void loop() 
{
  lcd.TouchCoordinates();    
  
  tempArr[counter] = sht.getTemperatureSHT();
  temp = average.Avr(tempArr, arrSize);
  
  humArr[counter] = sht.getHumiditySHT();
  humidity = average.Avr(humArr, arrSize);
  
  pressArr[counter] = bmp.getPressureBMP180();
  pressure = average.Avr(pressArr, arrSize);
    
  lcd.LCDPrint(temp,humidity,pressure);
  counter++;
  if(counter == arrSize)
  {
    counter = 0;
  }
}
