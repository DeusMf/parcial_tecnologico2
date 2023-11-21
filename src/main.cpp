#include <Arduino.h>
#include <pulsador.h>
#include "pwm.h"

// Definir los pines de los pulsadores
#define RED_BUTTON_PIN 2
#define GREEN_BUTTON_PIN 3
#define BLUE_BUTTON_PIN 4
#define INTENSITY_BUTTON_PIN 5

// Definir los pines del LED RGB
#define RED_PIN 6
#define GREEN_PIN 7
#define BLUE_PIN 8

// Declarar los objetos para los pulsadores y el PWM
pulsador redButton(RED_BUTTON_PIN, HIGH);
pulsador greenButton(GREEN_BUTTON_PIN, HIGH);
pulsador blueButton(BLUE_BUTTON_PIN, HIGH);
pulsador intensityButton(INTENSITY_BUTTON_PIN, HIGH);
PWM ledRGB(RED_PIN, GREEN_PIN, BLUE_PIN);

// Variables para almacenar la intensidad de cada color
int redIntensity = 0;
int greenIntensity = 0;
int blueIntensity = 0;

void setup() {
  // Configurar los pulsadores y el LED RGB
  redButton.LecturadelPulsador();
  greenButton.LecturadelPulsador();
  blueButton.LecturadelPulsador();
  intensityButton.LecturadelPulsador();
  ledRGB.setup();
}

void loop() {
  // Leer el estado de los pulsadores
  redButton.LecturadelPulsador();
  greenButton.LecturadelPulsador();
  blueButton.LecturadelPulsador();
  intensityButton.LecturadelPulsador();

  // Cambiar el color del LED RGB según el pulsador presionado
  if (redButton.getButtonState() == HIGH) {
    ledRGB.setColor(redIntensity, greenIntensity, blueIntensity); // Rojo
  } else if (greenButton.getButtonState() == HIGH) {
    ledRGB.setColor(redIntensity, greenIntensity, blueIntensity); // Verde
  } else if (blueButton.getButtonState() == HIGH) {
    ledRGB.setColor(redIntensity, greenIntensity, blueIntensity); // Azul
  }

  // Aumentar o disminuir la intensidad del color del LED si se presiona el pulsador de intensidad
  if (intensityButton.getButtonState() == HIGH) {
    // Aumentar la intensidad del color seleccionado si se presiona uno de los primeros tres pulsadores
    if (redButton.getButtonState() == HIGH) {
      redIntensity += 10;
    } else if (greenButton.getButtonState() == HIGH) {
      greenIntensity += 10;
    } else if (blueButton.getButtonState() == HIGH) {
      blueIntensity += 10;
    }
  } else {
    // Disminuir la intensidad del color seleccionado si se presiona uno de los primeros tres pulsadores
    if (redButton.getButtonState() == HIGH) {
      redIntensity -= 10;
    } else if (greenButton.getButtonState() == HIGH) {
      greenIntensity -= 10;
    } else if (blueButton.getButtonState() == HIGH) {
      blueIntensity -= 10;
    }
  }

  // Asegurar que la intensidad de cada color esté dentro del rango válido (0-255)
  redIntensity = constrain(redIntensity, 0, 255);
  greenIntensity = constrain(greenIntensity, 0, 255);
  blueIntensity = constrain(blueIntensity, 0, 255);
}