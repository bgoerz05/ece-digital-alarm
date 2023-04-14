#include "Arduino.h"
#include "NumberSegments.h"
#include "Display.h"
#include "Timekeeper.h"

Display::Display(int colon, int digits[], int segments[])
{
  colonPin = colon;
  pinMode(colonPin, OUTPUT);

  for(int i = 0; i <= 3; i++)
  {
    digitPins[i] = digits[i];
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);
  }
  
  for(int i = 0; i <= 6; i++)
  {
    segmentPins[i] = segments[i];
    pinMode(segmentPins[i], OUTPUT);
  }
}

// Digit should be a value between 0 and 3
// Value should be a single digit, 0-9
void Display::setDigit(int digit, int value)
{
  digitalWrite(digitPins[digit], LOW);

  switch (value)
  {
    case 0:
      segmentValues = zeroSegments;
      break;
    case 1:
      segmentValues = oneSegments;
      break;
    case 2:
      segmentValues = twoSegments;
      break;
    case 3:
      segmentValues = threeSegments;
      break;
    case 4:
      segmentValues = fourSegments;
      break;
    case 5:
      segmentValues = fiveSegments;
      break;
    case 6:
      segmentValues = sixSegments;
      break;
    case 7:
      segmentValues = sevenSegments;
      break;
    case 8:
      segmentValues = eightSegments;
      break;
    case 9:
      segmentValues = nineSegments;
      break;
    default:
      segmentValues = nullSegments;
      break;
  }
  
  for(int i = 0; i <= 6; i++) {
    digitalWrite(segmentPins[i], segmentValues[i]);
  }

  digitalWrite(digitPins[digit], HIGH);

  for(int i = 0; i <= 6; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
}

void Display::setHours(int value)
{
  setDigit(0, value / 10);
  setDigit(1, value % 10);
}

void Display::setMinutes(int value)
{
  setDigit(2, value / 10);
  setDigit(3, value % 10);
}

void Display::checkColon(Timekeeper& timer)
{
  if(timer.getSecond() % 2 == 0) 
  {
    digitalWrite(colonPin, HIGH);
  }
  else
  {
    digitalWrite(colonPin, LOW);
  }
}
