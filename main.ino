#include <Wire.h>
#include "BMP180.h"
#include <BMP180I2C.h>
#include <SHT21.h>  
#include "SHT.h"
#include <UTFT.h>
#include "LCD.h"
//#include "Coordinates.h"

SHT sht; 
BMP180 bmp;
LCD lcd;
float temp;
float humidity;
float pressure;
//Coordinates coordinates;


void setup() 
{
    Serial.begin(115200);
    Wire.begin();
    bmp.BMPSetUp();
    lcd.LCDSetUp();
    lcd.Draw();
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
