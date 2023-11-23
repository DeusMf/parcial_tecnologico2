#include "buttonToggle.h"

ButtonToggle::ButtonToggle(int buttonPin) {
  this->buttonPin = buttonPin;
  this->debounceDelay = 50;
  ledState = HIGH;  
  lastButtonState = LOW;
  lastDebounceTime = 0;
  pinMode(buttonPin, INPUT);

}



bool ButtonToggle::getButtonState() {
  bool band=false;
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState = !ledState;
        band=true;
      }
    }
  }
  lastButtonState = reading;
  return band;
}