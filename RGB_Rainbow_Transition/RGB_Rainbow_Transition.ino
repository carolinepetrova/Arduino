int redPin= 10;
int greenPin = 11;
int bluePin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  setColor(0, 255, 255); // To green Color
  delay(1000);
  // To green Color
  for(int i=0; i<=255; i++) {
  setColor(i, 255-i, 255); 
  delay(10);
  }
  setColor(255, 0, 255);
  delay(1000);
  // To blue Color
  for(int i=0; i<=255; i++) {
  setColor(255, i, 255-i); 
  delay(10);
  }
  setColor(255, 255, 0);
  delay(1000);
  // To red Color
  for(int i=0; i<=255; i++) {
  setColor(255-i, 255, i); 
  delay(10);
  }
}
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
