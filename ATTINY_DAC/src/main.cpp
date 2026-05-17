#include <Arduino.h>

const int apin[] = {A4, A5, A6, A7};
const int NUM_PINS = sizeof(apin) / sizeof(apin[0]);
const long BAUD_RATE = 9600;
static uint8_t data[NUM_PINS];

void setup() {
    Serial.begin(BAUD_RATE);
    analogReadResolution(10);
}

void loop() {
  for(int i=0;i<4;i++)Serial.write((i<<4)|((analogRead(apin[i])>>6)&0x0F));
  delay(100); 
}      

