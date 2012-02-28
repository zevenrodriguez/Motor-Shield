//MOTORSHIELD BASICS
//PWM-Set Speed
//BRAKE- Start and Stop Motor
//DIRECTION - Clockwise and Counter-clock

// give the motor control pins names:
const int pwmA = 3;
const int brakeA = 9;
const int dirA = 12;
const int pwmB = 11;
const int brakeB = 8;
const int dirB = 13;

int x = 0;
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
  //Move motorA counter-clockwise
  x = 0b101000;
  setMotorPins(x);

  delay(1000);

  x = 0b111000;
  setMotorPins(x);
  delay(1000);

  //Move motorA clockwise
  x = 0b100000;
  setMotorPins(x);

  delay(1000);

  x = 0b110000;
  setMotorPins(x);
  delay(1000);

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







