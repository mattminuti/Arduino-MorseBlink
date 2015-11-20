# Arduino-MorseBlink
Tiny little Arduino library to provide blinking out messages via morse code.
Uses delay() so it's target-neutral, but that means it's blocking.

Currently, just the latin alphabet is supported, as is space. No numbers, yet.

It's super-tiny, though! A quick test suggests it only adds about 500 bytes to a program that already uses the String class. Sure, I could just use char * instead, but most people who use arduino don't want to worry about that. :)

Example
-------
Super-easy to use! Just install into your libraries folder as usual, and include and instantiate like so:

 #include <MorseBlink.h>
 MorseBlink mymorse(13);

Now you can dit-dah your way to status-indication goodness!
 mymorse.blinkString("much info very morse");

