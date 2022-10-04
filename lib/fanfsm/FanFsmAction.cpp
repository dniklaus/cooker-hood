#include <DbgTracePort.h>
#include <DbgTraceLevel.h>
#include "FanFsm.h"
#include "FanFsmAction.h"

FanFsmAction::FanFsmAction()
: m_trPort(new DbgTrace_Port("fan", DbgTrace_Level::info))
, m_fanFsm(0)
{ }

FanFsmAction::~FanFsmAction()
{
  delete m_trPort;
  m_trPort = 0;
}

DbgTrace_Port* FanFsmAction::trPort()
{
  return m_trPort;
}

void FanFsmAction::attachFsm(FanFsm* fanFsm)
{
  m_fanFsm = fanFsm;
}

FanFsm* FanFsmAction::fanFsm()
{
  return m_fanFsm;
}
