#include "Constants.h"

// Variables for keeping track of the current time
int currentHour;
int currentMinute;
int currentSecond;

// Adds the time since the last update to the current time.
void updateTime();

void setup()
{
	
}

void loop()
{
	updateTime();

  // Debug prints
  Serial.print(currentHour);
  Serial.print(":");
  Serial.print(currentMinute);
  Serial.print(":");
  Serial.println(currentSecond);
}

void updateTime()
{
  static unsigned long lastUpdate;
  static unsigned long currentTime;

  // Update saved time
  int timeDiff = millis() - lastUpdate;
  lastUpdate = millis();
  currentTime += timeDiff;

  // Update time display values
  currentHour = (currentTime / msPerHour) % 24;
  currentMinute = (currentTime % msPerHour) / msPerMinute;
  currentSecond = (currentTime % msPerMinute) / msPerSecond;
}