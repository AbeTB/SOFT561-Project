#ifndef motorControl_h
#define motorControl_h

#include <Arduino.h>

class motorControl
{
  public:
    void motorSetup();
    void steerAngle();
    void leftTurn(int lSpeed);
    void rightTurn(int rSpeed);
    void brake();
	void forwardDrive(int dSpeed);
  private:
};

#endif
