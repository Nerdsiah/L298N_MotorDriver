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
  switch (cmd) {
  case FORWARD:
    CLR(PORTD, 4); // LOW
    SET(PORTD, 3); // HIGH  
    analogWrite(PWMpin, _pwmVal);
    break;
  case BACKWARD:
    SET(PORTD, 4); // HIGH
    CLR(PORTD, 3); // LOW
    analogWrite(PWMpin, _pwmVal);
    break;
  case BRAKE:
    SET(PORTD, 4); // HIGH
    SET(PORTD, 3); // HIGH
    analogWrite(PWMpin, _pwmVal);
    break;
  case RELEASE:
    CLR(PORTD, 4); // LOW
    CLR(PORTD, 3); // LOW
    analogWrite(PWMpin, _pwmVal);
    break;
  case LEFT:
    SET(PORTC, 0); // HIGH
    CLR(PORTC, 1); // LOW
    analogWrite(PWMpin, _pwmVal);
    break;
  case RIGHT:
    CLR(PORTC, 0); // LOW
    SET(PORTC, 1); // HIGH
    analogWrite(PWMpin, _pwmVal);
    break;
  case STRAIGHT:
    CLR(PORTC, 0); // LOW
    CLR(PORTC, 1); // LOW
    analogWrite(PWMpin, _pwmVal);
    break;
  }
}

void MotorDriver::setSpeed(uint8_t pwmVal)
{
  _pwmVal = pwmVal;
  return;
}
  

