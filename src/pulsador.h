#include <Arduino.h>

class pulsador {
private:
  int ledState;
  int buttonState;
  int lastButtonState;
  unsigned long lastDebounceTime;
  unsigned long debounceDelay;
  int ledPin;
  int buttonPin;
  
public:
  pulsador(int ledPin, int buttonPin) {
    // Inicializar Variables
    ledState = HIGH;
    buttonState = LOW; // Asignar un valor inicial a buttonState
    
    lastButtonState = LOW;
    lastDebounceTime = 0;
    debounceDelay = 50;
    
    // Guardar los pines proporcionados
    this->ledPin = ledPin;
    this->buttonPin = buttonPin;
    
    // Configurar pines como entrada y salida
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, ledState);
    pinMode(buttonPin, INPUT);
  }
  
  void LecturadelPulsador() {
    //Lee el estado del pulsador
    int reading = digitalRead(buttonPin);
    //Verifica si el estado del pulsador ha cambiado
    if (reading != lastButtonState) {
      lastDebounceTime = millis();
    }
    // Verificar si ha pasado el tiempo de debounce
    if ((millis() - lastDebounceTime) > debounceDelay) {
      //Actualiza el estado del pulsador
      if (reading != buttonState) {
        buttonState = reading;
        //cambia el estado del led si esta presionado
        if (buttonState == HIGH) {
          ledState = !ledState;
        }
      }
    }
    //Actualiza el estado del led
    digitalWrite(ledPin, ledState);
    lastButtonState = reading;
  }

  int getButtonState() {
    return buttonState;
  }
};