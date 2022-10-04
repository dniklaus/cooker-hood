#include <DbgTracePort.h>
#include <DbgTraceLevel.h>

#include "FanFsmAction.h"

FanFsmAction::FanFsmAction()
: m_trPort(new DbgTrace_Port("fanfsm", DbgTrace_Level::info))
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
