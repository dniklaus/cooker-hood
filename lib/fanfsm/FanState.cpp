#include <DbgTracePort.h>
#include <DbgTraceLevel.h>

#include "FanFsm.h"
#include "FanFsmAction.h"

#include "FanState.h"

void FanState::entry(FanFsm* fanFsm)
{
  if (0 != fanFsm->action())
  {
    TR_PRINTF(fanFsm->action()->trPort(), DbgTrace_Level::info, "Fan FSM, entering state %s [from %s]", fanFsm->state()->toString(), fanFsm->prevState()->toString());
  }
}
