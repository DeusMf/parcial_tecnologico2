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
   Serial.println(String(redButton.getButtonState()));
  // delay(10);
  // Leer el estado de los pulsadores
  /*redButton.loop();
  greenButton.loop();
  blueButton.loop();
  intensityButton.loop();

  // Aumentar la intensidad del color correspondiente al pulsador presionado
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

  // Disminuir la intensidad general del LED si se presiona el pulsador de intensidad
  if (intensityButton.getButtonState() == HIGH) {
    redIntensity -= 10;
    greenIntensity -= 10;
    blueIntensity -= 10;
    Serial.println("Botón de intensidad presionado");
  }

  // Asegurarse de que la intensidad esté dentro del rango permitido
  redIntensity = constrain(redIntensity, 0, 255);
  greenIntensity = constrain(greenIntensity, 0, 255);
  blueIntensity = constrain(blueIntensity, 0, 255);

  // Establecer la intensidad de cada color del LED RGB
  ledRGB.setColor(redIntensity, greenIntensity, blueIntensity);

  // Imprimir información de depuración
  Serial.print("Intensidad rojo: ");
  Serial.println(redIntensity);
  Serial.print("Intensidad verde: ");
  Serial.println(greenIntensity);
  Serial.print("Intensidad azul: ");
  Serial.println(blueIntensity);

  delay(100); // Agregar un pequeño retraso para evitar una salida de información excesiva en el monitor serial*/
}