#include <FanFsm.h>

#include "MyFanButtonAdapter.h"

//-----------------------------------------------------------------------------

MyFanLoButtonAdapter::MyFanLoButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
{ }

void MyFanLoButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    if (0 != m_fanFsm)
    {
      m_fanFsm->fanLowEvent();
    }
  }
}

//-----------------------------------------------------------------------------

MyFanHiButtonAdapter::MyFanHiButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
{ }

void MyFanHiButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    if (0 != m_fanFsm)
    {
      m_fanFsm->fanHighEvent();
    }
  }
}

//-----------------------------------------------------------------------------

MyFanTgButtonAdapter::MyFanTgButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
{ }

void MyFanTgButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    if (0 != m_fanFsm)
    {
      m_fanFsm->fanToggleEvent();
    }
  }
}

//-----------------------------------------------------------------------------

MyFanTimerButtonAdapter::MyFanTimerButtonAdapter(FanFsm* fanFsm)
: m_fanFsm(fanFsm)
{ }

void MyFanTimerButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (isActive)
  {
    if (0 != m_fanFsm)
    {
      m_fanFsm->timerExpiredEvent();
    }
  }
}
