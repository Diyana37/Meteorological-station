#include "LCD.h"
#include <UTFT.h>

UTFT myLCD(ITDB32S, 38, 39, 40, 41);
extern uint8_t BigFont[];
extern uint8_t SmallFont[];

void LCD::LCDSetUp()
{
  myLCD.InitLCD();
  myLCD.clrScr();
  myLCD.setFont(BigFont);
  myLCD.setBackColor(0, 0, 0);
}
