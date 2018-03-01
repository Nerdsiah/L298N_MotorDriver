# L298N Library
A easy to use L298N library to control DC Motors with Arduino.
This library was created for the purpose of controling RC car motors. Also, this libarary makes heavy use of port manipulation. 

## NOTICE
As you know, any L298N module has the ability to drive two motors at once, but you may not know that any instance of the library is intended to pilot only one motor. So if you need to drive two motors, you have to create another instance of the L298N object (one for each motor).

## INSTANCE THE MODULE
To drive a motor first create an instance of the library.

L298N myMotor;
