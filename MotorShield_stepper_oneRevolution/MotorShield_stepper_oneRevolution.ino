/* 
 Stepper Motor Control - one revolution
 for Arduino Motor Shield
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to the - and + pins of the shield.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
 
 
 Created 11 Mar. 2007
 Modified 21 May 2012
 by Tom Igoe and Zeven Rodriguez
 
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
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500); 
}

