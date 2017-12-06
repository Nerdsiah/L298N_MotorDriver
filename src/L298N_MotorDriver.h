#pragma once

// MotorDriver.h

#ifndef _L298N_MOTORDRIVER_h
#define _L298N_MOTORDRIVER_h

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

class L298N_MotorDriver;

class MotorDriver
{
public:
  MotorDriver();
  friend class L298N_MotorDriver;
  void run(uint8_t cmd);
  void setSpeed(uint8_t pwmVal);
  
private:
  uint8_t _pwmVal, PWMpin;
  uint8_t motornum;
};

class L298N_MotorDriver
{
public:
  L298N_MotorDriver();
  friend class MotorDriver;
  MotorDriver *getMotor(uint8_t n);

private:
  MotorDriver dcmotors[2];
};

#endif
