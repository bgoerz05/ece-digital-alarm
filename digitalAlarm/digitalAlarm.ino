#include "Timekeeper.h"

Timekeeper currentTimer;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop()
{
	currentTimer.updateTime();
}