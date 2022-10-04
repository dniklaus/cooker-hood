#include <FanFsm.h>
#include <FanFsmAction.h>
#include <DbgTracePort.h>
#include <DbgCliTopic.h>
#include <DbgCliNode.h>

#include "DbgCmd_FanLowerEvt.h"

DbgCmd_FanLowerEvt::DbgCmd_FanLowerEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode)
: DbgCli_Command(fanFsmEvtDbgCmdsNode, "low", "Send Fan Lower Button Fsm input event.")
, m_fanFsmAction(fanFsmAction)
{ }

DbgCmd_FanLowerEvt::~DbgCmd_FanLowerEvt()
{ }

void DbgCmd_FanLowerEvt::execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle)
{
  if (argc - idxToFirstArgToHandle != 0)
  {
    printUsage();
  }
  else
  {
    TR_PRINTF(m_fanFsmAction->trPort(), DbgTrace_Level::info, "Fan Fsm: emulate Fan Lower Button pressed event");
    if (0 != m_fanFsmAction)
    {
      if (0 != m_fanFsmAction->fanFsm())
      {
        m_fanFsmAction->fanFsm()->fanLowEvent();
      }
    }
  }
}

void DbgCmd_FanLowerEvt::printUsage()
{
  Serial.println(getHelpText());
  Serial.println("Usage: dbg fan evt low");
}
