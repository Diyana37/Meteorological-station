#ifndef LCD_H
#define LCD_H

class LCD
{
  public: 
  void LCDSetUp();
  void LCDPrint(float temp, float humidity, float pressure);
  void Draw(int bitmap[]);

};
#endif
