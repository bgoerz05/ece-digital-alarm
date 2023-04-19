#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer(int pin)
{
  pinMode(pin, OUTPUT);
  buzzerPin = pin;
}

void Buzzer::turnOnBuzzer()
{
  digitalWrite(buzzerPin, HIGH);
}

void Buzzer::turnOnBuzzer(int durationms)
{
  if (buzzerState == false)
  {
    buzzStartTime = millis();
    digitalWrite(buzzerPin, HIGH);
    buzzerState = true;
  }
  else
  {
    if (buzzStartTime + durationms <= millis())
    {
      buzzerState = false;
      digitalWrite(buzzerPin, LOW);
    }
  }
}

void Buzzer::beep(int periodms)
{
  if (millis() - (periodms / 2) >= lastChange) {
    state = !state;
    if (state) {
      turnOnBuzzer();
    } else {
      turnOffBuzzer();
    }
    lastChange = millis();
  }
}

void Buzzer::beep(int periodms, int duration)
{

}

void Buzzer::turnOffBuzzer()
{
  digitalWrite(buzzerPin, LOW);
}