#include "Constants.h"

// Variables for keeping track of the current time
int currentHour{0};
int currentMinute{0};
int currentSecond{0};
unsigned long currentTime{0};

// Adds the time since the last update to the current time.
void updateTime()
{
  static unsigned long lastUpdate;

  // Update saved time
  int timeDiff = millis() - lastUpdate;
  lastUpdate = millis();
  currentTime += timeDiff;

  // Update time display values
  currentHour = (currentTime / msPerHour) % 24;
  currentMinute = (currentTime % msPerHour) / msPerMinute;
  currentSecond = (currentTime % msPerMinute) / msPerSecond;
}

// Allows manually adjusting the time.
void addMinute()
{
  currentTime += msPerMinute;
}

void addHour()
{
  currentTime += msPerHour;
}