#include <FanFsm.h>
#include <FanFsmAction.h>
#include <DbgTracePort.h>
#include <DbgCliTopic.h>
#include <DbgCliNode.h>

#include "DbgCmd_FanToggleEvt.h"

DbgCmd_FanToggleEvt::DbgCmd_FanToggleEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode)
: DbgCli_Command(fanFsmEvtDbgCmdsNode, "tgl", "Send Fan Timer Button Fsm input event.")
, m_fanFsmAction(fanFsmAction)
{ }

DbgCmd_FanToggleEvt::~DbgCmd_FanToggleEvt()
{ }

void DbgCmd_FanToggleEvt::execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle)
{
  if (argc - idxToFirstArgToHandle != 0)
  {
    printUsage();
  }
  else
  {
    TR_PRINTF(m_fanFsmAction->trPort(), DbgTrace_Level::info, "Fan Fsm: emulate Fan Toggle Button pressed event");
    if (0 != m_fanFsmAction)
    {
      if (0 != m_fanFsmAction->fanFsm())
      {
        m_fanFsmAction->fanFsm()->fanToggleEvent();
      }
    }
  }
}

void DbgCmd_FanToggleEvt::printUsage()
{
  Serial.println(getHelpText());
  Serial.println("Usage: dbg fan evt tgl");
}
