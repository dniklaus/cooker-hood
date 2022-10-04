#include <DbgCliNode.h>
#include "DbgCmdTopic_Fan.h"

DbgCmdTopic_Fan::DbgCmdTopic_Fan()
: DbgCli_Topic(DbgCli_Node::RootNode(), "fan", "Fan Fsm commands.")
{ }
