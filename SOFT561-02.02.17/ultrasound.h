/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef ultrasound_h
#define ultrasound_h

#include "Arduino.h"

class ultrasound
{
  public:
    void setupUS();
	long getDistRight();
    long getDistLeft();

  private:

};

#endif