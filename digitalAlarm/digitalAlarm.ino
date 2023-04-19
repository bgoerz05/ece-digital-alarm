#include "Button.h"
#include "Display.h"
#include "Led.h"
#include "Timekeeper.h"

// Instantiates Timekeepers
Timekeeper currentTimer;
Timekeeper alarmTimer;

// Instantiates the display
int digitPins[4]{13, 10, 9, 6};
int segmentPins[7]{12, 8, 4, 3, 2, 11, 5};
Display display(7, digitPins, segmentPins);

// Button creations
void onAlarmRead(buttonState);
void onSnoozeRead(buttonState);
void onHourRead(buttonState);
void onMinuteRead(buttonState);

Button alarmButton(A0, onAlarmRead);
Button snoozeButton(A1, onSnoozeRead);
Button hourButton(A2, onHourRead);
Button minuteButton(A3, onMinuteRead);

bool alarmMode{ false };

void setup()
{
  Serial.begin(9600);
  currentTimer.addMinute();
  currentTimer.addHour();
  initLed(A5);
}

void loop()
{
	currentTimer.updateTime();
  display.checkColon(currentTimer);
  alarmButton.readButton();
  snoozeButton.readButton();
  hourButton.readButton();
  minuteButton.readButton();

  if (alarmMode)
  {
    display.setHours(alarmTimer.getHour());
    display.setMinutes(alarmTimer.getMinute());
    blinkLed(200);
  }
  else
  {
    display.setHours(currentHour);
    display.setMinutes(currentMinute);
    if (currentTimer.getRaw() >= alarmTimer.getRaw())
    {
      alarmGoingOff = true;
    }

    if (alarmGoingOff)
    {
      buzzer.turnOnBuzzer();
      fadeLedTriangle(3);
    }
    else
    {
      buzzer.turnOffBuzzer();
    }
  }
}

void onAlarmRead(buttonState state)
{
  if (state == PRESSED)
  {
    alarmMode = !alarmMode;
    turnOffLed();

    if (alarmGoingOff)
    {
      for (int i = 0; i <= 23; i++)
      {
        alarmTimer.addHour();
      }
      alarmGoingOff = false;
    }
    else
    {
      alarmMode = !alarmMode;
    }
    turnOffLed(); 
  }
}

void onSnoozeRead(buttonState state)
{

}

void onHourRead(buttonState state)
{
  if(state == PRESSED)
  {
    if (alarmMode)
    {
      alarmTimer.addHour();
    }
    else
    {
      currentTimer.addHour();
    }
  }
}

void onMinuteRead(buttonState state)
{
  if(state == PRESSED)
  {
    if (alarmMode)
    {
      alarmTimer.addMinute();
    }
    else
    {
      currentTimer.addMinute();
    }
  }
}