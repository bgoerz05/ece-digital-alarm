#include "Arduino.h"
#include "Timekeeper.h"
#include "Constants.h"

// Adds the time since the last update to the current time.
void Timekeeper::updateTime()
{
  int timeDiff = millis() - lastUpdate;
  lastUpdate = millis();
  currentTime += timeDiff;
}

// Allows manually adjusting the time.
void Timekeeper::addMinute()
{
  currentTime += msPerMinute;
}

void Timekeeper::addHour()
{
  currentTime += msPerHour;
}

// Gives useable values for the time
int Timekeeper::getHour() const
{
  return (currentTime / msPerHour) % 24;
}

int Timekeeper::getMinute() const
{
  return (currentTime % msPerHour) / msPerMinute;
}

int Timekeeper::getSecond() const
{
  return (currentTime % msPerMinute) / msPerSecond;
}

int Timekeerper::getRaw() const
{
  return currentTime;
}