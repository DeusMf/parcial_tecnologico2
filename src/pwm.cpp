#include "pwm.h"
#include <Arduino.h>

PWM::PWM(int redPin, int greenPin, int bluePin) {
  _redPin = redPin; // Asigna el pin del LED rojo a la variable miembro correspondiente
  _greenPin = greenPin; // Asigna el pin del LED verde a la variable miembro correspondiente
  _bluePin = bluePin; // Asigna el pin del LED azul a la variable miembro correspondiente
}

void PWM::setup() {
  pinMode(_redPin, OUTPUT); // Configura el pin del LED rojo como salida
  pinMode(_greenPin, OUTPUT); // Configura el pin del LED verde como salida
  pinMode(_bluePin, OUTPUT); // Configura el pin del LED azul como salida
}

void PWM::setColor(int red, int green, int blue) {

    ledcWrite(_redPin, red); // Establece el brillo del LED rojo
    ledcWrite(_greenPin, green); // Establece el brillo del LED verde
    ledcWrite(_bluePin, blue); // Establece el brillo del LED azul

} 