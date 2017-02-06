#include "motorControl.h"
#include "ultrasound.h"

int usSpeed = dist * 3;
ultrasound ultrasound;
motorControl motorControl;
long dist;

void setup() {
  // put your setup code here, to run once:
motorControl.motorSetup();
ultrasound.setupUS();
}

void loop() {
  // put your main code here, to run repeatedly:
long dist = ultrasound.getDistLeft();
motorControl.forwardDrive(usSpeed);

}
