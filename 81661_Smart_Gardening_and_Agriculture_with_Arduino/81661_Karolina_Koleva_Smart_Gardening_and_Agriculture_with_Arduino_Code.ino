#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity
int redpin = 11; // pin for red signal
int greenpin = 10; // pin for green signalint redpin = 11; // pin for red signal
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  int sensorValue = analogRead(A0);
  Serial.print(sensorValue);
  sensorValue = map(sensorValue, 1023, 465, 0, 100);
  
  sensorValue = abs(sensorValue);
  if(sensorValue < 35) {
    analogWrite(greenpin, 0);
    analogWrite(redpin, 255);
  }
  else if(sensorValue >=35 && sensorValue <=55) {
    analogWrite(redpin, 255);
  analogWrite(greenpin, 255);
  }
  else {
  analogWrite(redpin, 0);
  analogWrite(greenpin, 255);
  }
  lcd.print(sensorValue);
  lcd.print("%");
  delay(1000);
}
