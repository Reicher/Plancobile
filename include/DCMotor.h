#include <iostream>
#include <string>

#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

class DCMotor
{
 public:
  DCMotor(int gpioNum);
  ~DCMotor();

  void Set(float procent);
  
 private:
  void SetPwmTo(int pwm);
  int m_gpioNum, m_pwmRange;
};
