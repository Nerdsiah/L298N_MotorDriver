#ifndef _L298N_MotorDriver_h_
#define _L298N_MotorDriver_h_

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define CLR(x,y) (x&=(~(1<<y))) // direct port manipulation
#define SET(x,y) (x|=(1<<y)) // direct port manipulation

#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

#define LEFT 5
#define RIGHT 6
#define STRAIGHT 7

class L298N
{
public:
  void run(uint8_t);
  void steer(uint8_t);
  void setSpeed(uint8_t);
  uint8_t getSpeed();
  
private:
  uint8_t _speed, _EnableDrive, _EnableTurn;
};

#endif
