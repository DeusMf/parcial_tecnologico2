#include "pwm.h"
#include <Arduino.h>


PWM::PWM(int redPin, int greenPin, int bluePin, int ledChannelRed,int ledChannelGreen ,int ledChannelBlue) {
  _redPin = redPin; // Asigna el pin del LED rojo a la variable miembro correspondiente
  _greenPin = greenPin; // Asigna el pin del LED verde a la variable miembro correspondiente
  _bluePin = bluePin;
  _ledChannelRed = ledChannelRed;
  _ledChannelGreen = ledChannelGreen;
  _ledChannelBlue = ledChannelBlue; // Asigna el pin del LED azul a la variable miembro correspondiente
}

void PWM::setup() {
  pinMode(_redPin, OUTPUT); // Configura el pin del LED rojo como salida
  pinMode(_greenPin, OUTPUT); // Configura el pin del LED verde como salida
  pinMode(_bluePin, OUTPUT); // Configura el pin del LED azul como salida
  ledcSetup(_ledChannelRed, freq, resolution);
  ledcSetup(_ledChannelGreen, freq, resolution);
  ledcSetup(_ledChannelBlue, freq, resolution);
  ledcAttachPin(_redPin, _ledChannelRed);
  ledcAttachPin(_greenPin, _ledChannelGreen);
  ledcAttachPin(_bluePin, _ledChannelBlue);
}

void PWM::setColor(int red, int green, int blue) {

    ledcWrite(_ledChannelRed, red); // Establece el brillo del LED rojo
    ledcWrite(_ledChannelGreen, green); // Establece el brillo del LED verde
    ledcWrite(_ledChannelBlue, blue); // Establece el brillo del LED azul

} 