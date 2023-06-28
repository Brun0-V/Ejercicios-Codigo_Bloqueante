## Ejercicios - Código bloqueante y no bloqueante
<link rel="stylesheet" href="mdss-screen.min.css" media="screen">


**Realizar los siguientes ejercicios:**

***PARTE 1:***

**[Ejercicio 1.1](Ejercicios/EJ-1_1.cpp):** Realiza una baliza con 2 LEDs de colores diferentes. El primero debe titilar 1 vez por segundo mientras que el segundo debe titilar 4 veces por segundo.
```cpp
#define LED1 3
#define LED2 5
#define ON 1
#define OFF 0
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, ON);
  digitalWrite(LED2, ON);
  delay(125);
  digitalWrite(LED2, OFF);
  delay(125);
  digitalWrite(LED2, ON);
  delay(125);
  digitalWrite(LED2, OFF);
  delay(125);
  digitalWrite(LED1, OFF);
  digitalWrite(LED2, ON);
  delay(125);
  digitalWrite(LED2, OFF);
  delay(125);
  digitalWrite(LED2, ON);
  delay(125);
  digitalWrite(LED2, OFF);
  delay(125);
}
```
<div class="page"/>

**[Ejercicio 1.2](Ejercicios/EJ-1_2.cpp):** Realiza una baliza con 2 LEDs de colores diferentes. El primero debe titilar 3 vez por segundo mientras que el segundo debe titilar 4 veces por segundo.
```cpp
#define LED1 3
#define LED2 5
#define ON 1
#define OFF 0
int var = 0;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  if (var == 0){
    digitalWrite(LED1, ON);
    digitalWrite(LED2, ON);
  }
  if (var == 125)
    digitalWrite(LED2, OFF);
  if (var == 166)
    digitalWrite(LED1, OFF);
  if (var == 250)
    digitalWrite(LED2, ON);
  if (var == 333)
    digitalWrite(LED1, ON);
  if (var == 375)
    digitalWrite(LED2, OFF);
  if (var == 500){
    digitalWrite(LED2, ON);
    digitalWrite(LED1, OFF);
  }
  if (var == 625)
    digitalWrite(LED2, OFF);
  if (var == 666)
    digitalWrite(LED1, ON);
  if (var == 832)
    digitalWrite(LED1, OFF);
  if (var == 875)
    digitalWrite(LED2, ON);
  if (var == 1000){
    digitalWrite(LED2, OFF);
    digitalWrite(LED1, ON);
    var = -1;
  }
  delay(1);
  var++;
}
```
<div class="page"/>

**[Ejercicio 1.3](Ejercicios/EJ-1_3.cpp):** Investigar la función millis() del framework Arduino y utilizarla para volver a implementar el ejercicio anterior.
```cpp
#define LED1 3
#define LED2 5


unsigned long anterior = 0;
int diferencia = 10;
int time = 0;
bool flag_1 = 0;
bool flag_2 = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (millis() - anterior > diferencia){
    time++;
    anterior = millis();
    flag_1 = 0;
    flag_2 = 0;
  }
  if (time % 16 == 0){
    if (flag_1 == 0){
      digitalWrite(LED1, !digitalRead(LED1));
      flag_1 = 1;
    }
  }
  if (time % 12 == 0){
    if (flag_2 == 0){
      digitalWrite(LED2, !digitalRead(LED2));
      flag_2 = 1;
    }
  }
}
```
<div class="page"/>

***PARTE 2:***

**[Ejercicio 2.1](Ejercicios/EJ-2_1.cpp):** Realiza un semáforo (rojo -> rojo y amarillo -> verde -> amarillo) con modo nocturno (con un pulsador se accederá al modo nocturno que consiste en que cuando se presione el semáforo titilará en amarillo cada 2 segundos). No es obligatorio que el cambio de estado se inmediato.
```cpp
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
    delay(500); // Delay para evitar bounce del pulsador
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
      delay(500);
    }
  }
}
```
<div class="page"/>

**[Ejercicio 2.2](Ejercicios/EJ-2_2.cpp):** Realiza un semáforo (rojo -> rojo y amarillo -> verde -> amarillo) con modo nocturno (con un pulsador se accederá al modo nocturno que consiste en que cuando se presione el semáforo titilará en amarillo cada 2 segundos). Es obligatorio que el cambio de estado se inmediato.
```cpp
#define ON 1
#define OFF 0

#define pulsadorPin 2
#define LedR 3
#define LedA 4
#define LedV 5

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
      delay(500);
    }
}
```
<div class="page"/>

**[Ejercicio 2.3](Ejercicios/EJ-2_3.cpp):** Utiliza la función millis() para volver a implementar el ejercicio anterior.
```cpp
#define ON 1
#define OFF 0

#define pulsadorPin 2
#define LedR 3
#define LedA 4
#define LedV 5

#define tiempoRojo 5000
#define tiempoAmarillo 2000
#define tiempoVerde 5000
unsigned long static int anteriorMillis = 0;
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
      do
      {
        digitalWrite(LedR, ON);
        digitalWrite(LedA, OFF);
        digitalWrite(LedV, OFF);
      } while (millis() - anteriorMillis > tiempoRojo);
      anteriorMillis = millis();
      estado = ROJO_AMARILLO;
      break;

    case ROJO_AMARILLO:
      do
      {
        digitalWrite(LedR, ON);
        digitalWrite(LedA, ON);
        digitalWrite(LedV, OFF);
      } while (millis() - anteriorMillis < tiempoAmarillo);
      anteriorMillis = millis();
      estado = VERDE;
      break;

    case VERDE:
      do
      {
        digitalWrite(LedR, OFF);
        digitalWrite(LedA, OFF);
        digitalWrite(LedV, ON);
      } while (millis() - anteriorMillis < tiempoVerde);
      anteriorMillis = millis();
      estado = AMARILLO;
      break;

    case AMARILLO:
      do
      {
        digitalWrite(LedR, OFF);
        digitalWrite(LedA, ON);
        digitalWrite(LedV, OFF);
      } while (millis() - anteriorMillis < tiempoAmarillo);
      anteriorMillis = millis();
      estado = VERDE;
      break;
  }
}

void nightMode(){
  for (int ciclos = 0; ciclos < 10; ciclos++) {
      digitalWrite(LedA, !digitalRead(LedA));
      delay(500);
    }
}
```

*Entregar un PDF con los 3 códigos, junto a sus enunciados y adjuntar las conclusiones que crea pertinente a las diferentes problemáticas y soluciones.*
<div class="page"/>

## Conclusiones:

En mi opinión, los ejercicios presentados son muy útiles y proporcionan una introducción práctica a nuevas funciones y formas de resolver problemas con Arduino. Me gustó la forma en que los ejercicios fueron estructurados, comenzando con la creación de balizas con LEDs de diferentes colores y luego avanzando hacia la implementación de semáforos, yendo de más simple a más complejo.

En particular, me pareció interesante el uso de la función millis() en algunos de los ejercicios. Esta función permite un control más preciso del tiempo y evita problemas de sincronización al utilizar delays.

Sin embargo, me gustaría ver más ejercicios que presenten desafíos adicionales. Aunque los ejercicios actuales son buenos para comenzar, me gustaría tener la oportunidad de aplicar los conceptos aprendidos en problemas más complejos o proyectos prácticos.

En general, los ejercicios son una excelente manera de adquirir conocimientos básicos. Sin embargo, agregar más desafíos y proyectos prácticos podría enriquecer aún más la experiencia de aprendizaje.