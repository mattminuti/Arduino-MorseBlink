#ifndef MorseBlink_h
#define MorseBlink_h

#include "Arduino.h"

class MorseBlink {
  public:
    MorseBlink(int pin);
    void blinkChar(char c);
    void blinkString(String message);
    static unsigned int morse_dit_ms; //how many milliseconds should a dit be?
    int _pin;
  private:
    static const unsigned int morseTimings[];
};
#endif