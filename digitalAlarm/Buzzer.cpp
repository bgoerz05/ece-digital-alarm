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
  if (millis() - (periodms / 2) >= lastBuzzTime) {
    buzzerState = !buzzerState;
    if (buzzerState) {
      turnOnBuzzer();
    } else {
      turnOffBuzzer();
    }
    lastBuzzTime = millis();
  }
}

void Buzzer::beep(int periodms, int duration)
{

}

void Buzzer::turnOffBuzzer()
{
  digitalWrite(buzzerPin, LOW);
}