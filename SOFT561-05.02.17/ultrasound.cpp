#include "Arduino.h"
#include "ultrasound.h"

#define echoPinL 4 // Echo Pin
#define trigPinL 2 // Trigger Pin
#define echoPinR 3 // Echo Pin
#define trigPinR 5 // Trigger Pin

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance


void ultrasound::setupUS()
{

 Serial.begin (9600);
 pinMode(trigPinL, OUTPUT);
 pinMode(echoPinL, INPUT);
 pinMode(trigPinR, OUTPUT);
 pinMode(echoPinR, INPUT);

}

long ultrasound::getDistRight()
{

/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPinR, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinR, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinR, LOW);
 duration = pulseIn(echoPinR, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 return distance;
 }
 
 //Delay 50ms before next reading.
 delay(50);
 }

 long ultrasound::getDistLeft()
{

/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPinL, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinL, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinL, LOW);
 duration = pulseIn(echoPinL, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance); 
 return distance;
 }
 
 //Delay 50ms before next reading.
 delay(50);
 }
