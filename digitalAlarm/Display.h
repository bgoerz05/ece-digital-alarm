#ifndef DISPLAY_H
#define DISPLAY_H

#include "Timekeeper.h"
class Display
{
  private:
    int hours = 0;
    int minutes = 0;
    int colonPin;
    int digitPins[4];
    int segmentPins[7];
    int *segmentValues = nullptr;
    void setDigit(int, int);
  public:
    Display(int, int[], int[]);
    void setHours(int);
    void setMinutes(int);
    void checkColon(Timekeeper&);
};

#endif
