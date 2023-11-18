#include "pwm.h"
#include <Arduino.h>
PWM::PWM(int ledPin , int , int) {
  _ledPin = ledPin; // Asigna el pin del LED a la variable miembro correspondiente
  _freq = 5000; // Establece la frecuencia del PWM a 5000 Hz
  _ledChannel = 0; // Establece el canal del PWM a 0
  _resolution = 8; // Establece la resolución del PWM a 8 bits
}

void PWM::setup() {
  Serial.begin(115200); // Inicia la comunicación serial con una velocidad de 115200 baudios
  Serial.println(); // Imprime una línea en blanco en el monitor serial
  
  ledcSetup(_ledChannel, _freq, _resolution); // Configura el canal del PWM con la frecuencia y resolución especificadas
  ledcAttachPin(_ledPin, _ledChannel); // Asocia el pin del LED al canal del PWM
}

void PWM::loop() {
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(_ledChannel, dutyCycle); // Cambia el ciclo de trabajo del PWM para controlar el brillo del LED
    delay(4); // Pausa la ejecución durante 4 milisegundos
  }
  
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(_ledChannel, dutyCycle); // Cambia el ciclo de trabajo del PWM para controlar el brillo del LED
    delay(4); // Pausa la ejecución durante 4 milisegundos
  }
}