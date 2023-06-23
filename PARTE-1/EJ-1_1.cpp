#include <Arduino.h>
#define LED1 3
#define LED2 5
#define ON 1
#define OFF 0
//1 p0, a500
//2 p0 a125, p250 a375, p500 a 625, p750 a875 
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  //0
  digitalWrite(LED1, ON);
  digitalWrite(LED2, ON);
  delay(125);//125
  digitalWrite(LED2, OFF);
  delay(125);//250
  digitalWrite(LED2, ON);
  delay(125);//375
  digitalWrite(LED2, OFF);
  delay(125);//500
  digitalWrite(LED1, OFF);
  digitalWrite(LED2, ON);
  delay(125);//625
  digitalWrite(LED2, OFF);
  delay(125);//750
  digitalWrite(LED2, ON);
  delay(125);//875
  digitalWrite(LED2, OFF);
  delay(125);//1000
}