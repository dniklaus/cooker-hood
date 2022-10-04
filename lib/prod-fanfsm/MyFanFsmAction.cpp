#include <Indicator.h>
#include <DbgCliNode.h>
#include <DbgCliCommand.h>
#include "DbgCmdTopic_FanEvt.h"
#include "DbgCmd_FanLowerEvt.h"
#include "DbgCmd_FanHigherEvt.h"
#include "DbgCmd_FanToggleEvt.h"
#include "DbgCmd_FanTimerEvt.h"
#include "MyFanFsmAction.h"

MyFanFsmAction::MyFanFsmAction(Indicator* fan1Relay, Indicator* fan2Relay, Indicator* fan3Relay)
: m_fan1Relay(fan1Relay)
, m_fan2Relay(fan2Relay)
, m_fan3Relay(fan3Relay)
, m_fanFsmEvtLowerEvtCmd(new DbgCmd_FanLowerEvt(this, new DbgCmdTopic_FanEvt()))
, m_fanFsmEvtHigherEvtCmd(new DbgCmd_FanHigherEvt(this, m_fanFsmEvtLowerEvtCmd->getParentNode()))
, m_fanFsmEvtToggleEvtCmd(new DbgCmd_FanToggleEvt(this, m_fanFsmEvtLowerEvtCmd->getParentNode()))
, m_fanFsmEvtTimerEvtCmd(new DbgCmd_FanTimerEvt(this, m_fanFsmEvtLowerEvtCmd->getParentNode()))
{ 
  actFanOff();
}

MyFanFsmAction::~MyFanFsmAction()
{ 
  delete m_fanFsmEvtLowerEvtCmd->getParentNode();

  delete m_fanFsmEvtLowerEvtCmd;
  m_fanFsmEvtLowerEvtCmd = 0;

  delete m_fanFsmEvtHigherEvtCmd;
  m_fanFsmEvtHigherEvtCmd = 0;

  delete m_fanFsmEvtToggleEvtCmd;
  m_fanFsmEvtToggleEvtCmd = 0;
}

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
