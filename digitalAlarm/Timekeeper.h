#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

class Timekeeper
{
  private:
    unsigned long currentTime = 0.0;
    unsigned long lastUpdate = 0.0;
  public:
    void updateTime();
    void addMinute();
    void addHour();
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
};

#endif
