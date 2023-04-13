const int ledPin2 = 2; // The digital pin for LED 2
const int ledPin3 = 3; // The PWM pin for LED 3
const int ledPin9 = 9; // The PWM pin for LED 9
const int ledPin5 = 5; // The digital pin for LED 5
const int ledPin6 = 6; // The digital pin for LED 6
const int brightnessStep3 = 2; // The amount to increment or decrement brightness of LED 3 each time
const int brightnessStep9 = -brightnessStep3; // The amount to increment or decrement brightness of LED 9 each time
int brightness3 = 0; // The current brightness of LED 3
int brightness9 = 255-brightness3; // The current brightness of LED 9
int direction3 = 1; // The direction of brightness change for LED 3
int direction9 = - direction3; // The direction of brightness change for LED 9

void setup() {
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
}

void loop() {
  // Blinking effect on LED 2
  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2, LOW);
  delay(500);
  
  // Breathing effect on LED 3
  analogWrite(ledPin3, brightness3);
  brightness3 += direction3 * brightnessStep3;
  if (brightness3 <= 0 || brightness3 >= 255) {
    direction3 = -direction3;
  }
  
  // Breathing effect on LED 9
  analogWrite(ledPin9, brightness9);
  brightness9 = 255 - brightness3;
  
  // Turning on LEDs
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);
  
  delay(50); // Set the delay time between steps to 50ms
}

