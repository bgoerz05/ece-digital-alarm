#ifndef BUTTON_H
#define BUTTON_H

typedef enum
{
  PRESSED,
  HELD,
  RELEASED
} buttonState;

// this is a function pointer for the callback function for the button class
typedef void (*buttonCallback)(buttonState currentState); 


class Button
{
  public:
    Button(int pin, buttonCallback incallback);
    void readButton();
  private:
    int buttonPin;
    bool buttonValue = true;
    bool prevValue = true;
    bool prevCleanValue = true;
    unsigned long impulseTime = 0;
    buttonCallback callback;
};

#endif