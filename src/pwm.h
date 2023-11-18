#ifndef Pwm_h
#define Pwm_h

#include <Arduino.h>

class PWM {
  public:
    PWM(int ledPin, int , int); // Constructor de la clase PWM
    void setup(); // Método para realizar la configuración inicial
    void loop(); // Método que se ejecuta en bucle
  
  private:
    int _ledPin; // Variable para almacenar el pin del LED
    int _freq; // Variable para almacenar la frecuencia del PWM
    int _ledChannel; // Variable para almacenar el canal del PWM
    int _resolution; // Variable para almacenar la resolución del PWM
};

#endif