#include <Arduino.h>
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