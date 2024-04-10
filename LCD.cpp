#include "LCD.h"
#include <UTFT.h>

UTFT myLCD(ITDB32S, 38, 39, 40, 41);
extern uint8_t BigFont[];
extern uint8_t SmallFont[];
extern uint8_t SevenSegNumFont[];

void LCD::LCDSetUp()
{
  myLCD.InitLCD();
  myLCD.clrScr();
  myLCD.setFont(BigFont);
  myLCD.setBackColor(255,20,147);
  myLCD.fillScr(255,20,147);
}

void LCD::LCDPrint(float temp, float humidity, float pressure)
{
  int tempI = temp;
  int tempD = 100 * (temp - tempI);
  
  String tempI_S = String(tempI);  
  String tempD_S = String(tempD);

  myLCD.setColor(255,255,255);
  myLCD.fillRect(0,119,319,121);
  myLCD.fillRect(159,0,161,120);
  
  myLCD.setFont(SevenSegNumFont);
  myLCD.print(tempI_S, 75, 157);
  myLCD.print(tempD_S, 170, 157);
  
  myLCD.setFont(BigFont);
  myLCD.setColor(255,255,255);
  myLCD.print(".", CENTER, 190);


  String humidityS = String(humidity);
  myLCD.print(humidityS, 40, 55);


  String pressureS = String(pressure);
  myLCD.print(pressureS, 190, 55);
}

void LCD:: Draw(int bitmap[])
{
  myLCD.drawBitmap(20, 150, 50, 62, bitmap);
}
