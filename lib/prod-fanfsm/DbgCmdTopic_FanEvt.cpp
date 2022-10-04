#include <DbgCliNode.h>
#include "DbgCmdTopic_Fan.h"
#include "DbgCmdTopic_FanEvt.h"

DbgCmdTopic_FanEvt::DbgCmdTopic_FanEvt()
: DbgCli_Topic(new DbgCmdTopic_Fan(), "evt", "Fan Fsm Event commands.")
{ }

DbgCmdTopic_FanEvt::~DbgCmdTopic_FanEvt()
{
  delete getParentNode();
}
