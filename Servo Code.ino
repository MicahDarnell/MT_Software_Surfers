#include <Servo.h>

Servo myservo;  // create servo variable
Servo myservo2;
const int buttonPin = 2;
const int buttonPin2 = 3;


void setup() {
  myservo.attach(9);
  myservo.write(80);
  myservo2.attach(8);
  myservo.write(80);
  //attaches the servo on pin 9 pinMode(buttonPin, INPUT);
}


void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    myservo.write(150); //tells the servo what angle to turn to 0 - 180
      } else {
      myservo.write(80);
    }

      if (digitalRead(buttonPin2) == HIGH) {
    myservo2.write(115); //tells the servo what angle to turn to 0 - 180
      } else {
      myservo2.write(80);
    }
  }