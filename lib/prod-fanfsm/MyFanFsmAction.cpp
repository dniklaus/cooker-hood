#include <Indicator.h>

#include "MyFanFsmAction.h"

MyFanFsmAction::MyFanFsmAction(Indicator* fan1Relay, Indicator* fan2Relay, Indicator* fan3Relay)
: m_fan1Relay(fan1Relay)
, m_fan2Relay(fan2Relay)
, m_fan3Relay(fan3Relay)
{ 
  actFanOff();
}

MyFanFsmAction::~MyFanFsmAction()
{ }

void MyFanFsmAction::actFan1()
{
  m_fan1Relay->clear();
  m_fan2Relay->set();
}

void MyFanFsmAction::actFan2()
{
  m_fan1Relay->set();
  m_fan2Relay->set();
}

void MyFanFsmAction::actFan3()
{
  m_fan1Relay->set();
  m_fan2Relay->clear();
}

void MyFanFsmAction::actFanOff()
{
  m_fan1Relay->clear();
  m_fan2Relay->clear();
  m_fan3Relay->clear();
}
