#include <Arduino.h>
#define ON 1
#define OFF 0

#define LedR = 2
#define LedA = 3
#define LedV = 4
#define pulsadorPin = 5

#define tiempoRojo = 5000
#define tiempoAmarillo = 2000
#define tiempoVerde = 5000
bool modoNocturno = false;

enum EstadoSemaforo {
  ROJO,
  ROJO_AMARILLO,
  VERDE,
  AMARILLO
};
EstadoSemaforo estado = ROJO;

void setup() {
  pinMode(LedR, OUTPUT);
  pinMode(LedA, OUTPUT);
  pinMode(LedV, OUTPUT);
  pinMode(pulsadorPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pulsadorPin) == LOW) {
    modoNocturno = !modoNocturno;
    delay(500); // Retardo para evitar rebotes del pulsador
  }
  switch (estado) {
    case ROJO:
      digitalWrite(LedR, ON);
      digitalWrite(LedA, OFF);
      digitalWrite(LedV, OFF);
      delay(tiempoRojo);
      estado = ROJO_AMARILLO;
      break;

    case ROJO_AMARILLO:
      digitalWrite(LedR, ON);
      digitalWrite(LedA, ON);
      digitalWrite(LedV, OFF);
      delay(tiempoAmarillo);
      estado = VERDE;
      break;

    case VERDE:
      digitalWrite(LedR, OFF);
      digitalWrite(LedA, OFF);
      digitalWrite(LedV, ON);
      delay(tiempoVerde);
      estado = AMARILLO;
      break;

    case AMARILLO:
      digitalWrite(LedR, OFF);
      digitalWrite(LedA, ON);
      digitalWrite(LedV, OFF);
      delay(tiempoAmarillo);
      estado = ROJO;
      break;
  }

  if (modoNocturno && estado == AMARILLO) {
    for (int ciclos = 0; ciclos < 10; ciclos++) {
      digitalWrite(LedA, !digitalRead(LedA));
      delay(1000);
    }
  }
}
