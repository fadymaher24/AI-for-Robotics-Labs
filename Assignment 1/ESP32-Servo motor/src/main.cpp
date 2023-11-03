#include <ESP32Servo.h>

const int servoPin = 18;
const int potentiometerPin = 34;

Servo servo;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  // Read the value from the potentiometer
  int potValue = analogRead(potentiometerPin);

  // Map the potentiometer value to the servo position (0-180 degrees)
  // max for esp32 3.3v is 4095
  int pos = map(potValue, 0, 4095, 0, 180);
  
  // Move the servo to the mapped position
  servo.write(pos);
  
  // Delay for smoother servo movement
  delay(15);
}
