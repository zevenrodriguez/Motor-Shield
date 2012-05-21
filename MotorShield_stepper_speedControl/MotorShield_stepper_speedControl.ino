
/* 
 Stepper Motor Control - speed control
 for Arduino Motor Shield
  
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to the - and + pins of the shield.
 A potentiometer is connected to analog input 0.
 
 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps, 
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.
 
 Created 30 Nov. 2009
 Modified 21 May 2012
 by Tom Igoe
  
 This example code is in the public domain.
 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor

// these are the pins connected to the Arduino Motor Shield:                                    
const int pwmA = 3;
const int brakeA = 9;
const int dirA = 12;
const int pwmB = 11;
const int brakeB = 8;
const int dirB = 13;       

int stepCount = 0;         // number of steps the motor has taken


/*
  Initialize the stepper library using the direction pins (dirA and dirB) 
 to control the motor shield. For more details, see the Stepper motor pages, 
 starting with http://arduino.cc/en/Reference/Stepper
 */
Stepper myStepper(stepsPerRevolution, dirA,dirB);            

void setup() {
  // set up all of the pins of the motor shield as outputs:
  pinMode(pwmA, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(dirA, OUTPUT);  
  pinMode(pwmB, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(dirB, OUTPUT);

  // set the brake pins LOW to turn them off:
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  // set the pwm pins HIGH to give maximum power to the motor:
  digitalWrite(pwmA, HIGH); 
  digitalWrite(pwmB, HIGH);

  // set the speed at 60 rpm:
  myStepper.setSpeed(60);

  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution/100);
  } 
}


