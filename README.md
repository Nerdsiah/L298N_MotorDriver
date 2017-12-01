# L298N Library
A easy to use L298N library to control DC Motors with Arduino.

## NOTICE
As you know, any L298N module has the ability to drive two motors at once, but you may not know that any instance of the library is intended to pilot only one motor. So if you need to drive two motors, you have to instance two L298N object (one for each motor).

#include <L298N.h>

## INSTANCE THE MODULE
To drive a motor the first create an instance of the library.

L298N myMotor;