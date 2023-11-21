#ifndef Pwm_h
#define Pwm_h

#include <Arduino.h>

class PWM {
  public:
    PWM(int redPin, int greenPin, int bluePin); // Constructor de la clase PWM
    void setup(); // Método para realizar la configuración inicial
    void setColor(int red, int green, int blue); // Método para establecer el color del LED

  private:
    int _redPin; // Variable para almacenar el pin del LED rojo
    int _greenPin; // Variable para almacenar el pin del LED verde
    int _bluePin; // Variable para almacenar el pin del LED azul
};

#endif  