#include "motorControl.h"
#include "ultrasound.h"

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
motorControl.leftTurn(140);
long dist = ultrasound.getDistLeft();
}
