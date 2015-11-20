#include <MorseBlink.h>

//Set up which pin the morse-ing will happen on
MorseBlink morse(13);

void setup(){
	//nothing needed
}

void main(){
	//Morse out the message. Can be upper or lowercase, latin alphabet, plus spaces.
	morse.blinkString("Hello world");
	
	delay(5000); //delay so that we can clearly see the message's end.
}
