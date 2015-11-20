#include "Arduino.h"
#include "MorseBlink.h"

const unsigned int MorseBlink::morseTimings[] ={0x0D,0x57,0x77,0x17,0x01,0x75,0x1F,0x55,0x05,0xFD,0x37,0x5D,0x0F,0x07,0x3F,0x7D,0xDF,0x1D,0x15,0x03,0x35,0xD5,0x3D,0xD7,0xF7,0x5F};

unsigned int MorseBlink::morse_dit_ms = 200;

//Constructor
MorseBlink::MorseBlink(int pin){
  // initialize this instance's variables
  pinMode(pin,OUTPUT);
  _pin = pin;
}

// Public Methods
void MorseBlink::blinkString(String message){
  message.toUpperCase();
  for( int i=0; i<message.length(); i++){
    MorseBlink::blinkChar(message[i]); //blink out the character
    delay(morse_dit_ms*2); //delay two more to finish out end-of-char or space.
  }
}

void MorseBlink::blinkChar(char c){
  Serial.println(this->_pin);
  if(c == ' '){
    //special handling for space - it's just 7 units of delay.
    //we autodelay two after each char, so just need to do 5 here.
    delay(morse_dit_ms*5);
    return; //our job here is done.
  }
  c -= 'A'; //our timings chart starts at A.
  uint8_t ourTimings = morseTimings[c];
  uint8_t duration = ourTimings & 3; //mask off the last two bits, that's how long the tone is
  do {
    digitalWrite(this->_pin,HIGH);
    delay(duration*morse_dit_ms);
    digitalWrite(_pin,LOW);
    delay(morse_dit_ms);
    duration = (ourTimings >>= 2) & 3;
  } while(duration != 0); //if the tone is zero, we're done.
}