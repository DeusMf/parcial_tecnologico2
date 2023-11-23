#ifndef BUTTON_TOGGLE_H
#define BUTTON_TOGGLE_H

#include <Arduino.h>

class ButtonToggle {
public:
  ButtonToggle(int buttonPin);


  bool getButtonState(); // Agrega la declaración de la función getButtonState
  int getLedState();
private:
  int buttonPin;
  int lastButtonState;
  unsigned long lastDebounceTime;
  unsigned long debounceDelay;
  int buttonState;
  int ledState;
};

#endif