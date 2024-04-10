#include <Wire.h>
#include "BMP180.h"
#include <BMP180I2C.h>
#include <SHT21.h>  
#include "SHT.h"
#include <UTFT.h>
#include "LCD.h"

SHT sht; 
BMP180 bmp;
LCD lcd;
float temp;
float humidity;
float pressure;

void setup() 
{
    Serial.begin(115200);
    Wire.begin();
    bmp.BMPSetUp();
    lcd.LCDSetUp();
}
  
void loop() 
{
  delay (500);
  Serial.println(bmp.getTemperatureBMP180());
  //Serial.println(bmp.getPressureBMP180());
  Serial.println(sht.getTemperatureSHT());
  //Serial.println(sht.getHumiditySHT());
  Serial.println("////////////");
  temp = sht.getTemperatureSHT();
  humidity = sht.getHumiditySHT();
  pressure = bmp.getPressureBMP180();
  lcd.LCDPrint(temp,humidity,pressure);
}
