#pragma once

// MotorDriver.h

#ifndef _L298N_MotorDriver_h
#define _L298N_MotorDriver_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// uncomment to use direct port manipulation with Arduino Uno
// will cause compiler errors if uncommented when using Arduino Due
//#define CLR(x,y) (x&=(~(1<<y))) // direct port manipulation set pin LOW
//#define SET(x,y) (x|=(1<<y)) // direct port manipulation set pin HIGH

// use inside of .cpp file
/*
  example:
  CLR(PORTC, 0); // analog pin A0 set to LOW
  SET(PORTC, 1); // analog pin A1 set to HIGH
*/

/*
PIO_PER  - write 1's here to override other peripherals and allow GPIO use for pins
PIO_OER  - write 1's here to set pins as OUTPUT
PIO_ODR  - write 1's here to set pins as INPUT
* PIO_SODR   - write 1's here to set output pins HIGH
* PIO_CODR   - write 1's here to set output pins LOW
* PIO_PDSR  - read's actual state of the pins on the port.
PIO_PUDR  - write 1's here to switch off internal pull-up for pins
PIO_PUER  - write 1's here to switch on internal pull-up for pins
*/

// uncomment to use direct port manipulation with Arduino Due
// will cause compiler errors if uncommented when using Arduino Uno
#define REG_PIO[port]_OER = 0x1 << [port Pin]; // set pins to OUTPUT
#define REG_PIO[port]_SODR = 0x1 << [Pin mask]; // Pin HIGH
#define REG_PIO[port]_CODR = 0x1 << [port Pin]; // Pin LOW

// use inside of .cpp file
/*
  example:
  REG_PIOA_OER = 0x1 << 16; // analog pin A0 set to OUTPUT
  REG_PIOA_OER = 0x1 << 24; // analog pin A1 set to OUTPUT
  
  REG_PIOA_SODR = 0x1 << 16; // HIGH  
  REG_PIOA_CODR = 0x1 << 24; // LOW
*/

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
