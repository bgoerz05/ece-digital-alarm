#ifndef LED_H
#define LED_H

int ledPin;

unsigned long lastChange{0};
unsigned long lastFade{0};

bool state{false};
int brightness{0};

int increment{1};

void initLed(int pin){
  ledPin = pin;
}

void turnOnLed(){
  digitalWrite(ledPin, HIGH);
}

void turnOffLed(){
  digitalWrite(ledPin, LOW);
}

void blinkLed(int periodms){
  if (millis() - (periodms / 2) >= lastChange) {
    state = !state;
    if (state) {
      turnOnLed();
    } else {
      turnOffLed();
    }
    lastChange = millis();
  }
}

void blinkLed(int periodms,int durationms){
  unsigned long endTime = millis() + durationms;
  while (millis() < endTime) {
    if (millis() - (periodms / 2) >= lastChange) {
      state = !state;
      if (state) {
        turnOnLed();
      } else {
        turnOffLed();
      }
      lastChange = millis();
    }
  }
  turnOffLed();
}

void fadeLedSawtooth(int periodms){
  if (millis() - (periodms / 255) >= lastFade) {
    brightness = (++brightness) % 255;
    analogWrite(ledPin, brightness);
    lastFade = millis();
  }
}

void fadeLedSawtooth(int periodms,int durationms){
  unsigned long endTime = millis() + durationms;
    while (millis() < endTime) {
       if (millis() - (periodms / 255) >= lastFade) {
      brightness = (++brightness) % 255;
      analogWrite(ledPin, brightness);
      lastFade = millis();
    }
  }
  turnOffLed();
}

void fadeLedTriangle(int periodms){
  if(millis()-lastfadetime>=periodms){
    brightness=(brightness +increment);
    if(brightness>=255){
      increment = -1;
    }
    if(brightness<=0){
      increment = 1;
    }
      analogWrite(ledpin,brightness);
      lastfadetime=millis();
  
  } 
  

}

void fadeLedTriangle(int periodms,int durationms){
  unsigned long endTime = millis() + durationms;
    while (millis() < endTime) {
       if (millis() - (periodms / 255) >= lastFade) {
      if (brightness >= 255) {
        increment = -1;
      } else if (brightness <= 0) {
        increment = 1;
      }
      brightness = brightness + increment;
      analogWrite(ledPin, brightness);
      lastFade = millis();
    }
  }
  turnOffLed();
}

#endif