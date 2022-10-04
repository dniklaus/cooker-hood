#pragma once

#include <FanFsmAction.h>

class Indicator;

class MyFanFsmAction : public FanFsmAction
{
public:
  MyFanFsmAction(Indicator* fan1Relay, Indicator* fan2Relay, Indicator* fan3Relay);
  virtual ~MyFanFsmAction();

  void actFan1();
  void actFan2();
  void actFan3();
  void actFanOff();

private:
  Indicator* m_fan1Relay;
  Indicator* m_fan2Relay;
  Indicator* m_fan3Relay;

private:  // forbidden default functions
  MyFanFsmAction();                                       // default constructor
  MyFanFsmAction(const MyFanFsmAction& src);              // copy constructor
  MyFanFsmAction& operator = (const MyFanFsmAction& src); // assignment operator
};
