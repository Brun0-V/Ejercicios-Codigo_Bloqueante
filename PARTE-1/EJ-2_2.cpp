#include <Arduino.h>
#define ON 1
#define OFF 0

#define LedR 3
#define LedA 4
#define LedV 5
#define pulsadorPin 2

#define tiempoRojo 5000
#define tiempoAmarillo 2000
#define tiempoVerde 5000
bool modoNocturno = false;
void nightMode();

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
  attachInterrupt(digitalPinToInterrupt(pulsadorPin), nightMode, LOW);
  Serial.begin(9600);
}

void loop() {
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
}

void nightMode(){
  for (int ciclos = 0; ciclos < 10; ciclos++) {
      digitalWrite(LedA, !digitalRead(LedA));
      delay(1000);
    }
}