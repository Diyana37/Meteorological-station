#ifndef LCD_H
#define LCD_H
#include "Coordinates.h";

class LCD
{
  public: 
  void LCDSetUp();
  void LCDPrint(float temp, float humidity, float pressure);
  void Draw();
  Coordinates TouchCoordinates();

};
#endif
