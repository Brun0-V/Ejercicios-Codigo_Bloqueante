<<<<<<< Updated upstream
#include <Arduino.h>
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
=======
#include <Arduino.h>
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
>>>>>>> Stashed changes
}