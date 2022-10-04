#include <FanFsm.h>
#include <FanFsmAction.h>
#include <DbgTracePort.h>
#include <DbgCliTopic.h>
#include <DbgCliNode.h>

#include "DbgCmd_FanHigherEvt.h"

DbgCmd_FanHigherEvt::DbgCmd_FanHigherEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode)
: DbgCli_Command(fanFsmEvtDbgCmdsNode, "high", "Send Fan Lower Button Fsm input event.")
, m_fanFsmAction(fanFsmAction)
{ }

DbgCmd_FanHigherEvt::~DbgCmd_FanHigherEvt()
{ }

void DbgCmd_FanHigherEvt::execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle)
{
  if (argc - idxToFirstArgToHandle != 0)
  {
    printUsage();
  }
  else
  {
    if (0 != m_fanFsmAction)
    {
      TR_PRINTF(m_fanFsmAction->trPort(), DbgTrace_Level::info, "Fan Fsm: emulate Fan Higher Button pressed event");
      if (0 != m_fanFsmAction->fanFsm())
      {
        m_fanFsmAction->fanFsm()->fanHighEvent();
      }
    }
  }
}

void DbgCmd_FanHigherEvt::printUsage()
{
  Serial.println(getHelpText());
  Serial.println("Usage: dbg fan evt high");
}
