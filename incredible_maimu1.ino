#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int sPin1 = A0;  
int sPin2 = A1;
int val1;    // variable to read the value from the analog pin
int val2;
int servomax = 180;
int servomin = 0;
int led1 = 3;


void setup() {
  pinMode(sPin1, INPUT);
  pinMode(sPin2, INPUT);
  pinMode(led1, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led1, HIGH);
  int sVal1 = analogRead(sPin1);
  int sVal2 = analogRead(sPin2);
  int serpos1 = map(sVal1, 0, 1023, 0, 180);
  int serpos2 = map(sVal2, 0, 1023, 0, 180);
  
  Serial.print ("sVal1:  ");
  Serial.print (serpos1);
  Serial.print ("  sVal2:  ");
  Serial.println (serpos2);
  
  if(serpos1 < 60 && serpos2 < 70)
  {
    myservo.write(servomin);
    delay(1000);
  }
  if(serpos1 >= 61 && serpos2 < 70)
  {
    myservo.write(servomax);
    delay(1000);
  }
  if(serpos1 > 110 && serpos2 > 70)
  {
    myservo.write(servomin);
    digitalWrite(led1, LOW);
    delay(1000);
    
  }


  
  
}