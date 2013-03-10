#include "../include/DCMotor.h"

DCMotor::DCMotor(int gpioNum)
  : m_gpioNum(gpioNum)
  , m_pwmRange(100)
{
  if(wiringPiSetup() == -1)
    return;

  if(softPwmCreate(m_gpioNum, 0, m_pwmRange) != 0)
    return; 
}

DCMotor::~DCMotor()
{
  //NOTHING
}

void DCMotor::Set(float procent)
{
  if(procent > 1 || procent < 0)
    return;

  SetPwmTo(m_pwmRange * procent);
}

void DCMotor::SetPwmTo(int pwm)
{
  softPwmWrite(m_gpioNum, pwm);
}
	
