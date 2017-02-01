#include "Arduino.h"
#include "motorControl.h"

const int pwmA  = 3;
const int pwmB  = 11;
const int brakeA  = 9;
const int brakeB  = 8;
int lSpeed;
int rSpeed;
int dSpeed;

void motorControl::motorSetup()
{
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
}

void motorControl::steerAngle()
{
  digitalWrite(6, HIGH);
  delay(250);
  digitalWrite(6, LOW);
  delay(250);  
}

void motorControl::leftTurn(int lSpeed)
{
  digitalWrite(brakeA, HIGH);
  digitalWrite(brakeB, LOW);
  analogWrite(pwmA, 0);
  analogWrite(pwmB, lSpeed); 
}

void motorControl::rightTurn(int rSpeed)
{
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, HIGH);
  analogWrite(pwmA, rSpeed);
  analogWrite(pwmB, 0); 
}

void motorControl::brake()
{
  digitalWrite(brakeA, HIGH);
  digitalWrite(brakeB, HIGH);
  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0); 
}

void motorControl::forwardDrive(int dSpeed)
{
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  analogWrite(pwmA, dSpeed);
  analogWrite(pwmB, dSpeed); 
}


