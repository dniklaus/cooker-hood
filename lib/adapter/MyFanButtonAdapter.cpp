#include <FanFsm.h>
#include <DbgTracePort.h>
#include <DbgTraceLevel.h>
#include "MyFanButtonAdapter.h"

//-----------------------------------------------------------------------------

MyFanLoButtonAdapter::MyFanLoButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
, m_trPort(new DbgTrace_Port("fanlobtn", DbgTrace_Level::info))
{ }

void MyFanLoButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    TR_PRINTF(m_trPort, DbgTrace_Level::info, "Button pressed")
    if (0 != m_fanFsm)
    {
      m_fanFsm->fanLowEvent();
    }
  }
}

//-----------------------------------------------------------------------------

MyFanHiButtonAdapter::MyFanHiButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
, m_trPort(new DbgTrace_Port("fanhibtn", DbgTrace_Level::info))
{ }

void MyFanHiButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    TR_PRINTF(m_trPort, DbgTrace_Level::info, "Button pressed")
    if (0 != m_fanFsm)
    {
      m_fanFsm->fanHighEvent();
    }
  }
}

//-----------------------------------------------------------------------------

MyFanTgButtonAdapter::MyFanTgButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
, m_trPort(new DbgTrace_Port("fantgbtn", DbgTrace_Level::info))
{ }

void MyFanTgButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    TR_PRINTF(m_trPort, DbgTrace_Level::info, "Button pressed")
    if (0 != m_fanFsm)
    {
      m_fanFsm->fanToggleEvent();
    }
  }
}

//-----------------------------------------------------------------------------

MyFanTimerButtonAdapter::MyFanTimerButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
, m_trPort(new DbgTrace_Port("fantmbtn", DbgTrace_Level::info))
{ }

void MyFanTimerButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    if (0 != m_fanFsm)
    {
      TR_PRINTF(m_trPort, DbgTrace_Level::info, "Button pressed")
      m_fanFsm->timerStartEvent();
    }
  }
}
