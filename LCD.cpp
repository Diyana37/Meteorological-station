#include "LCD.h"
#include <UTFT.h>
#include <URTouch.h>
#include "Coordinates.h"
#include "Inconsola.c"
#include "ArialNumFontPlus.c"

UTFT myLCD(ITDB32S, 38, 39, 40, 41);
URTouch Touch(6, 5, 4, 3, 2);
Coordinates coordinates;
_Bool isFarenhait = false;

//fonts
extern uint8_t BigFont[];
extern uint8_t SmallFont[];
extern uint8_t SevenSegNumFont[];
extern const uint8_t Inconsola[];
extern const uint8_t ArialNumFontPlus[];

//bitmaps
extern unsigned int thermometer[];
extern unsigned int waterdrop[];
extern unsigned int barometer[];

void LCD::LCDSetUp()
{
  myLCD.InitLCD();
  myLCD.clrScr();
  myLCD.setFont(BigFont);
  myLCD.setBackColor(255,20,147);
  myLCD.fillScr(255,20,147);
  myLCD.setBrightness(16);
  Touch.InitTouch();
  Touch.setPrecision(PREC_MEDIUM);
}

void LCD::LCDPrint(float temp, float humidity, float pressure)
{
  //temperature
  if(!isFarenhait)
  {
    int tempW = temp;//whole part of temperature
    int tempD = 100 * (temp - tempW);//decimal part of temperature
  
    String tempW_S = String(tempW);  
    String tempD_S = String(tempD);

    myLCD.setFont(ArialNumFontPlus);
    myLCD.print(tempW_S, 85, 157);
    myLCD.print(tempD_S, 170, 157);

    myLCD.setFont(Inconsola);
    myLCD.setColor(255,255,255);
    myLCD.print(".", CENTER, 180);

    myLCD.print("`C", 232, 140);//celsius
  }
  else
  {
    float tempF = (temp * 9.0 / 5.0) + 32.0;//temperature in Farenhait
    int tempW = tempF; // Whole part of temperature in Fahrenheit
    int tempD = 100 * (tempF - tempW); // Decimal part of temperature in Fahrenheit

    String tempW_S = String(tempW);  
    String tempD_S = String(tempD);

    myLCD.setFont(ArialNumFontPlus);
    myLCD.print(tempW_S, 85, 157);
    myLCD.print(tempD_S, 170, 157);

    myLCD.setFont(Inconsola);
    myLCD.setColor(255,255,255);
    myLCD.print(".", CENTER, 180);

    
    myLCD.setFont(Inconsola);
    myLCD.print("`F", 232, 140);//farenhait
  }

  myLCD.setColor(255,255,255);
  myLCD.fillRect(0,119,319,121);//separating line
  myLCD.fillRect(159,0,161,120);//separating line

  //humidity
  String humidityS = String(humidity);
  myLCD.print(humidityS, 10, 55);

  //pressure
  String pressureS = String(pressure);
  myLCD.print(pressureS, 168, 55);

  //display unit of measure
  myLCD.print("%", 135, 55);//humidity
  myLCD.setFont(BigFont);
  myLCD.print("hPa", 233, 23);//pressure
}

void LCD:: Draw()
{
  myLCD.drawBitmap(23, 148, 50, 62, thermometer);
  myLCD.drawBitmap(55, 10, 30, 34, waterdrop);
  myLCD.drawBitmap(195, 10, 30, 41, barometer);
}

Coordinates LCD:: TouchCoordinates()
{
  if(Touch.dataAvailable())
  {
    Touch.read();
    coordinates.x = Touch.getX();
    coordinates.y = Touch.getY();
  }
  if(coordinates.x>0 && coordinates.x<320 && coordinates.y>120 && coordinates.y<240)
  {
     isFarenhait = !isFarenhait;
     return coordinates;
  }
  else
  {
    coordinates.x = 1000;
    coordinates.y = 1000;
    return coordinates;
  }
}
