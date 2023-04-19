#include "Button.h"
#include "Arduino.h"

Button::Button(int pin, buttonCallback incallback)
{
  pinMode(pin, INPUT_PULLUP);
  buttonPin = pin;
  callback = incallback;
}

void Button::readButton()
{
  buttonValue = digitalRead(buttonPin);
  if (buttonValue != prevValue) {
    impulseTime = millis();
  }
  if (millis() - impulseTime > 50) {
    if (buttonValue != prevCleanValue) {
      // Executes once after state change
      if (buttonValue == 1) {
        callback(RELEASED);
      } else {
        callback(PRESSED);
      }
    }
    prevCleanValue = buttonValue;
  }
  prevValue = buttonValue;
}