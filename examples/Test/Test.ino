#include "L298N_MotorDriver.h"

// motor instances 
L298N_MotorDriver MD = L298N_MotorDriver();

MotorDriver *DriveMotor = MD.getMotor(1);
MotorDriver *TurnMotor = MD.getMotor(2);

void setup()
{
  
}

void loop() 
{
  DriveMotor->setSpeed(100);
  DriveMotor->run(FORWARD);
  TurnMotor->setSpeed(255);
  TurnMotor->run(LEFT);
  delay(1000);

  DriveMotor->setSpeed(100);
  DriveMotor->run(BACKWARD);
  TurnMotor->setSpeed(255);
  TurnMotor->run(RIGHT);
  delay(1000);
}
