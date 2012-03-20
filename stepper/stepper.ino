



// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to




// for your motor
const int pwmA = 3;
const int brakeA = 9;
const int dirA = 12;
const int pwmB = 11;
const int brakeB = 8;
const int dirB = 13;
// initialize the stepper library on pins 8 through 11:
int delayNum = 20;

void setup() {

  Serial.begin(9600);

  pinMode(pwmA, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(dirA, OUTPUT);  
  pinMode(pwmB, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(dirB, OUTPUT);

  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);


}

void loop() {


  digitalWrite(pwmA, HIGH);
  digitalWrite(dirA, HIGH);
  delay(delayNum);

  digitalWrite(pwmB, HIGH);
  digitalWrite(dirB, HIGH);
  delay(delayNum);


  digitalWrite(pwmA, HIGH);
  digitalWrite(dirA, LOW);
  delay(delayNum); 

  digitalWrite(pwmB, HIGH);
  digitalWrite(dirB, LOW);

  delay(delayNum);
}




