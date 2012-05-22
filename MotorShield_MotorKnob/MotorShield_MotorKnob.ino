/*
   MotorKnob
   for Arduino Motor Shield
   
   A stepper motor follows the turns of a potentiometer
   (or other sensor) on analog input 0.
   The motor is attached to the - and + pins of the shield.

   http://www.arduino.cc/en/Reference/Stepper
   
   Created by David A. Mellis
   Modified 21 May 2012
   by Tom Igoe
   
   This example code is in the public domain.
 */

#include <Stepper.h>


const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor


// the previous reading from the analog input
int lastSensorValue = 0;

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
}

void loop()
{
  // get the sensor value
  int sensorValue = analogRead(A0);

  // move a number of steps equal to the change in the
  // sensor reading
  myStepper.step(sensorValue - lastSensorValue);

  // remember the previous value of the sensor
  lastSensorValue = sensorValue;
}
