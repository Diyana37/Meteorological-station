#include "Average.h"

float Average:: Avr(float arr[], int arrSize)
{
  float sum = 0;
  for(int i = 0; i < arrSize; i++)
  {
    sum = sum + arr[i];
  }
  return sum / arrSize;
}
