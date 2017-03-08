#include "motorControl.h"
#include "ultrasound.h"
#include "FastIO.h"
#include "I2CIO.h"
#include "LCD.h"
#include "LiquidCrystal.h"
#include "LiquidCrystal_I2C.h"
#include "Wire.h" 

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
long dist;
int usSpeed = dist * 3;
ultrasound ultrasound;
motorControl motorControl;


void setup() {
Serial.begin(9600);
lcd.begin(16,2);
motorControl.motorSetup();
ultrasound.setupUS();
}

void loop() {
lcd.setCursor(0,0);
lcd.print("Mode: Active");  
  // put your main code here, to run repeatedly:
long dist = ultrasound.getDistLeft();
motorControl.forwardDrive(usSpeed);


}
