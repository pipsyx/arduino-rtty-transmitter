#ifndef RTTY_h
#define RTTY_h

#include "Arduino.h"

class RTTY5
{
  public:
    byte rtty_pin;
    RTTY5();
	void attach(byte pin);
	void tx (char* string);
    
  private:
    void rtty_txbyte (byte c);
    void rtty_txbit (bool bit);

};

extern RTTY5 RTTY;

#endif // RTTY_h
