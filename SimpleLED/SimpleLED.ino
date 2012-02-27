 // give the motor control pins names:
const int pwmA = 3;
const int pwmB = 11;
const int brakeA = 9;
const int brakeB = 8;
const int dirA = 12;
const int dirB = 13;

int x = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(dirA, OUTPUT);  
  pinMode(dirB, OUTPUT);
 //setMotorPins(0b000101); 
}
void loop() {
 if (millis() % 2000 < 10) {
 if (x == 0b000101) x = 0b000100;
 else x = 0b000101;
 
  setMotorPins(x); 
 }
int motorBCurrent = analogRead(A1);
Serial.println(motorBCurrent);
delay(30);



}

void setMotorPins(byte pinState) {
  // pring the pin states as a binary number:
 // Serial.println(pinState, BIN); 
  
  // read each of the 6 bits and assign each to a pin:
  digitalWrite(pwmA, bitRead(pinState, 5));
  digitalWrite(brakeA, bitRead(pinState, 4));
  digitalWrite(dirA, bitRead(pinState, 3));  
  digitalWrite(pwmB, bitRead(pinState, 2));
  digitalWrite(brakeB, bitRead(pinState, 1));
  digitalWrite(dirB, bitRead(pinState, 0));

}



