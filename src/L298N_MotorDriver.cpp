#pragma once

#include "Arduino.h"
#include "L298N_MotorDriver.h"

L298N_MotorDriver::L298N_MotorDriver() {}

MotorDriver *L298N_MotorDriver::getMotor(uint8_t num)
{
  if (num > 2) return NULL;

  num--;

  if (dcmotors[num].motornum == 0) {
    // not init'd yet!
    dcmotors[num].motornum = num;
    uint8_t pwm;
    if (num == 0) {
      pwm = 5;
    }
    else if (num == 1) {
      pwm = 6;
    }
    dcmotors[num].PWMpin = pwm;
  }
  return &dcmotors[num];
}

/******************************************
               MOTORS
******************************************/

MotorDriver::MotorDriver()
{
  motornum = 0;
  PWMpin = 0;
}

void MotorDriver::run(uint8_t cmd)
{
  // analog pins A0-A3 used for driving motors using port manipulation on the Arduino Due
  // all pins on the Arduino Due must set to INPUT or OUTPUT
  // this is not required when using the Arduino Uno
  REG_PIOA_OER = 0x1 << 16; // pin set to OUTPUT
  REG_PIOA_OER = 0x1 << 22; // pin set to OUTPUT
  REG_PIOA_OER = 0x1 << 23; // pin set to OUTPUT
  REG_PIOA_OER = 0x1 << 24; // pin set to OUTPUT
  
  switch (cmd) {
// controls drive motor only    
  case FORWARD:
    REG_PIOA_CODR = 0x1 << 24; // LOW
    REG_PIOA_SODR = 0x1 << 16; // HIGH  
//    CLR(PORTD, 4); // LOW
//    SET(PORTD, 3); // HIGH 
    analogWrite(PWMpin, _pwmVal);
    break;
  case BACKWARD:
    REG_PIOA_SODR = 0x1 << 24; // HIGH
    REG_PIOA_CODR = 0x1 << 16; // LOW
//    SET(PORTD, 4); // HIGH
//    CLR(PORTD, 3); // LOW
    analogWrite(PWMpin, _pwmVal);
    break;
  case BRAKE:
    REG_PIOA_SODR = 0x1 << 24; // HIGH
    REG_PIOA_SODR = 0x1 << 16; // HIGH
//    SET(PORTD, 4); // HIGH
//    SET(PORTD, 3); // HIGH
    analogWrite(PWMpin, _pwmVal);
    break;
  case RELEASE:
    REG_PIOA_CODR = 0x1 << 24; // LOW
    REG_PIOA_CODR = 0x1 << 16; // LOW
//    CLR(PORTD, 4); // LOW
//    CLR(PORTD, 3); // LOW
    analogWrite(PWMpin, _pwmVal);
    break;
// controls steering motor only    
  case LEFT:
    REG_PIOA_SODR = 0x1 << 23; // HIGH
    REG_PIOA_CODR = 0x1 << 22; // LOW
//    SET(PORTC, 0); // HIGH
//    CLR(PORTC, 1); // LOW
    analogWrite(PWMpin, _pwmVal);
    break;
  case RIGHT:
    REG_PIOA_CODR = 0x1 << 23; // LOW
    REG_PIOA_SODR = 0x1 << 22; // HIGH
//    CLR(PORTC, 0); // LOW
//    SET(PORTC, 1); // HIGH
    analogWrite(PWMpin, _pwmVal);
    break;
  case STRAIGHT:
    REG_PIOA_CODR = 0x1 << 23; // LOW
    REG_PIOA_CODR = 0x1 << 22; // LOW
//    CLR(PORTC, 0); // LOW
//    CLR(PORTC, 1); // LOW
    break;
  }
}

void MotorDriver::setSpeed(uint8_t pwmVal)
{
  _pwmVal = pwmVal;
  return;
}
  
