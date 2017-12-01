#include "Arduino.h"
#include "L298N_MotorDriver.h"

void L298N::setSpeed(uint8_t speed) 
{
  _speed = speed;
  return;
}

uint8_t L298N::getSpeed()
{
  return _speed;
}
void L298N::run(uint8_t cmd) 
{
  // pins 3 and 4 are used for drive motor output
  const uint8_t EnableDrivePin = 5; // pwm pin for drive motor
  _EnableDrive = EnableDrivePin;
  
  switch (cmd) {
  case FORWARD:
    CLR(PORTD, 4); // LOW
    SET(PORTD, 3); // HIGH  
    analogWrite(_EnableDrive, _speed);
  break;
  case BACKWARD:
    SET(PORTD, 4); // HIGH
    CLR(PORTD, 3); // LOW
    analogWrite(_EnableDrive, _speed);
  break;
  case RELEASE:
    CLR(PORTD, 4); // LOW
    CLR(PORTD, 3); // LOW
    analogWrite(_EnableDrive, _speed);
  break;
  case BRAKE:
    SET(PORTD, 4); // HIGH
    SET(PORTD, 3); // HIGH
    analogWrite(_EnableDrive, _speed);
  break;
  }
}

void L298N::steer(uint8_t cmd) 
{
  // pins 14 and 15 are used for steering motor output
  const uint8_t EnableTurnPin = 6;
  _EnableTurn = EnableTurnPin;
  
  switch (cmd) {
  case 5:
    // left
    SET(PORTC, 0); // HIGH
    CLR(PORTC, 1); // LOW
    analogWrite(_EnableTurn, _speed);
  break;
  case 6:
    // right
    CLR(PORTC, 0); // LOW
    SET(PORTC, 1); // HIGH
    analogWrite(_EnableTurn, _speed);
  break;
  case 7:
    CLR(PORTC, 0); // LOW
    CLR(PORTC, 1); // LOW
    analogWrite(_EnableTurn, _speed);
  break;
  }
}

