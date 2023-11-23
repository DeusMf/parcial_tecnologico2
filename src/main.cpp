#include <Arduino.h>
#include "buttonToggle.h"
#include "pwm.h"

// Definir los pines de los pulsadores
#define RED_BUTTON_PIN 35
#define GREEN_BUTTON_PIN 34
#define BLUE_BUTTON_PIN 39
#define INTENSITY_BUTTON_PIN 36

// Definir los pines del LED RGB
#define RED_PIN 13
#define GREEN_PIN 12
#define BLUE_PIN 14

// Declarar los objetos para los pulsadores y el PWM
ButtonToggle redButton(RED_BUTTON_PIN);
ButtonToggle greenButton(GREEN_BUTTON_PIN);
ButtonToggle blueButton(BLUE_BUTTON_PIN);
ButtonToggle intensityButton(INTENSITY_BUTTON_PIN);
PWM ledRGB(RED_PIN, GREEN_PIN, BLUE_PIN, 0, 1, 2);

int redIntensity = 0;
int greenIntensity = 0;
int blueIntensity = 0;  

void setup() {
  Serial.begin(115200); // Inicializar el monitor serial

  // Configurar el PWM para el LED RGB
  ledRGB.setup();

}

void loop() {
   intensityButton.getButtonState(); 
   int band = intensityButton.getLedState();
  // Aumentar la intensidad del color correspondiente al pulsador presionado
  if (band)
  {
    if (redButton.getButtonState() == HIGH) {
    redIntensity += 10;
    Serial.println("Botón rojo presionado");
  } else if (greenButton.getButtonState() == HIGH) {
    greenIntensity += 10;
    Serial.println("Botón verde presionado");
  } else if (blueButton.getButtonState() == HIGH) {
    blueIntensity += 10;
    Serial.println("Botón azul presionado");
  }
  }else{
    if (redButton.getButtonState() == HIGH) {
    redIntensity -= 10;
    Serial.println("Botón rojo presionado");
  } else if (greenButton.getButtonState() == HIGH) {
    greenIntensity -= 10;
    Serial.println("Botón verde presionado");
  } else if (blueButton.getButtonState() == HIGH) {
    blueIntensity -= 10;
    Serial.println("Botón azul presionado");
  }
  }
  
  ledRGB.setColor(redIntensity, greenIntensity, blueIntensity);

 
}