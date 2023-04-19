#include "Timekeeper.h"
#include "Display.h"

// Instantiates a Timekeeper, which will manage the current time
Timekeeper currentTimer;

// Instantiates the display
int digitPins[4]{13, 10, 9, 6};
int segmentPins[7]{12, 8, 4, 3, 2, 11, 5};
Display display(7, digitPins, segmentPins);

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
