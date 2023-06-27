#include <Arduino.h>
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
