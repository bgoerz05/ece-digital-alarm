#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
  public:
    Buzzer(int pin);
    void turnOnBuzzer();
    void turnOnBuzzer(int durationms);
    void beep(int periodms);
    void beep(int periodms, int duration);
    void turnOffBuzzer();
  private:
    bool buzzerState;
    unsigned long lastBuzzTime;
    unsigned long buzzStartTime;
    int buzzerPin;
};


#endif