/*
 Motor Shield: DC Motor
 By Zevensuy Rodriguez
 
 This example is setup for 2 DC Motor. 
 
 This is the basic pin setup for the motor shield.
 
 Channel A
 Direction: Digital Pin 12
 PWM: Digital Pin 3
 Brake: Digital Pin 9
 Current Sense: Analog Pin A0
 
 Channel B
 Direction: Digital Pin 13
 PWM: Digital Pin 11
 Brake: Digital Pin 8
 Current Sense: Analog Pin A1  
 */


//Channel A Setup
const int pwmA = 3;
const int brakeA = 9;
const int dirA = 12;


//Channel B Setup
const int pwmB = 11;
const int brakeB = 8;
const int dirB = 13;


void setup() {
  Serial.begin(9600);
  //Channel A Setup    
  pinMode(pwmA, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(dirA, OUTPUT); 

  //Channel B Setup  
  pinMode(pwmB, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(dirB, OUTPUT);

}

void loop() {
  
  int channelA = analogRead(A0);
  int channelB = analogRead(A1);
  
  Serial.println("Current of channel A is: " + channelA);
  Serial.println("Current of channel B is: " + channelB);

  //Channel A 
  //Direction: Clockwise, Brake: OFF
  digitalWrite(pwmA, HIGH);
  digitalWrite(brakeA, LOW);
  digitalWrite(dirA, HIGH); 

  //Channel B
  //Direction: Clockwise, Brake: OFF
  digitalWrite(pwmB, HIGH);
  digitalWrite(brakeB, LOW);
  digitalWrite(dirB, HIGH);

  delay(1000);
  
  //Channel A 
  //Direction: Counter-Clockwise, Brake: OFF
  digitalWrite(pwmA, HIGH);
  digitalWrite(brakeA, LOW);
  digitalWrite(dirA, LOW); 

  //Channel B
  //Direction: Counter-Clockwise, Brake: OFF
  digitalWrite(pwmB, HIGH);
  digitalWrite(brakeB, LOW);
  digitalWrite(dirB, LOW);

  delay(1000);

}



