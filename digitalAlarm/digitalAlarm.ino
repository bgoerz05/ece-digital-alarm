#include "Timekeeper.h"
#include "Display.h"
#include "Button.h"

// Instantiates a Timekeeper, which will manage the current time
Timekeeper currentTimer;

// Instantiates the display
int digitPins[4]{13, 10, 9, 6};
int segmentPins[7]{12, 8, 4, 3, 2, 11, 5};
Display display(7, digitPins, segmentPins);
// Button alarmButton(A0,);
// Button snoozeButton(A1,);
// Button hourButton(A2,);
// Button minuteButton(A3,);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
	currentTimer.updateTime();
  display.checkColon(currentTimer);

  // Test code -- counts seconds and minutes since start.
  display.setHours(currentTimer.getMinute());
  display.setMinutes(currentTimer.getSecond());
}
