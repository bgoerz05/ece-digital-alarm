#include "Timekeeper.h"

Timekeeper currentTimer;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	currentTimer.updateTime();
  Serial.print(currentTimer.getHour());
  Serial.print(":");
  Serial.print(currentTimer.getMinute());
  Serial.print(":");
  Serial.println(currentTimer.getSecond());
}