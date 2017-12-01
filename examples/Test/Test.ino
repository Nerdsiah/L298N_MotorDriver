#include <L298N_MotorDriver.h>

// motor instances 
L298N *Drive;
L298N *Turn;

void setup()
{
  
}

void loop() 
{
  Turn->setSpeed(255);
  Turn->steer(LEFT);
  Drive->setSpeed(150);
  Drive->run(FORWARD);
  delay(1000);
  
  Turn->setSpeed(255);
  Turn->steer(RIGHT);
  Drive->setSpeed(150);
  Drive->run(BACKWARD);
  delay(1000);
}
