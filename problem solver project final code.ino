const int buttonPin = 2;
int buttonState;
int previousButtonState = 0;
const int sensorPin = 0;
const int ledPin = 9;
const int piezoPin = 4;

int lightLevel, high = 0, low = 1023;
bool isOn = false;
int sensorVal;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (previousButtonState != buttonState){
    if (buttonState == HIGH){
      isOn = !isOn;
    }
  }

  if (isOn){
    sensorVal = digitalRead(sensorPin);

    if (sensorVal == HIGH){
      lightLevel = analogRead(sensorPin);
      autoTune();  
      analogWrite(ledPin, 255-lightLevel);
    } else {
      analogWrite(piezoPin, 0); 
    }
  } else {
    analogWrite(piezoPin, 0); 
    digitalWrite(ledPin, LOW); 
  }
  
  previousButtonState = buttonState;
}

void manualTune()
{
  lightLevel = map(lightLevel, 300, 800, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
} 

void autoTune()
{
  if (lightLevel > high)
  {
    analogWrite(piezoPin, 128); 
    high = lightLevel;
  }

  if (lightLevel < low)
  {
    low = lightLevel;
  }

  lightLevel = map(lightLevel, low+30, high-30, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
  analogWrite(piezoPin, 255 - lightLevel); 
}



