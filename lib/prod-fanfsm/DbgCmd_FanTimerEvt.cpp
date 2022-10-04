#include <FanFsm.h>
#include <FanFsmAction.h>
#include <DbgTracePort.h>
#include <DbgCliTopic.h>
#include <DbgCliNode.h>

#include "DbgCmd_FanTimerEvt.h"

DbgCmd_FanTimerEvt::DbgCmd_FanTimerEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode)
: DbgCli_Command(fanFsmEvtDbgCmdsNode, "tim", "Send Fan Timer Button Fsm input event.")
, m_fanFsmAction(fanFsmAction)
{ }

DbgCmd_FanTimerEvt::~DbgCmd_FanTimerEvt()
{ }

void DbgCmd_FanTimerEvt::execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle)
{
  if (argc - idxToFirstArgToHandle != 0)
  {
    printUsage();
  }
  else
  {
    if (0 != m_fanFsmAction)
    {
      if (0 != m_fanFsmAction->fanFsm())
      {
        TR_PRINTF(m_fanFsmAction->trPort(), DbgTrace_Level::info, "Fan Fsm: emulate Fan Timer Button pressed event");
        m_fanFsmAction->fanFsm()->timerStartEvent(5000);
      }
    }
  }
}

void DbgCmd_FanTimerEvt::printUsage()
{
  Serial.println(getHelpText());
  Serial.println("Usage: dbg fan evt tim");
}
