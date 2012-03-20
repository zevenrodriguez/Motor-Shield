  /*
  Motor Shield Setup
  
  Motor 1
  Direction: Digital Pin 12
  PWM: Digital Pin 3
  Brake: Digital Pin 9
  Current Sense: Analog Pin A0
  
  Motor 1
  Direction: Digital Pin 13
  PWM: Digital Pin 11
  Brake: Digital Pin 8
  Current Sense: Analog Pin A1  
  */
const int pwmA = 3;
const int brakeA = 9;
const int dirA = 12;
const int pwmB = 11;
const int brakeB = 8;
const int dirB = 13;


void setup() {
  Serial.begin(9600);
  pinMode(pwmA, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(dirA, OUTPUT);  
  pinMode(pwmB, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(dirB, OUTPUT);

}

void loop() {

  int sensorValue = analogRead(A5)/4;
  Serial.println(sensorValue);
  
  analogWrite(pwmA, sensorValue);
  digitalWrite(brakeA, LOW);
  digitalWrite(dirA, HIGH); 
  /* Motor 2
  int sensorValue = analogRead(A5)/4;
  Serial.println(sensorValue);
  
  analogWrite(pwmA, sensorValue);
  digitalWrite(brakeA, LOW);
  digitalWrite(dirA, HIGH); 
  */
}
