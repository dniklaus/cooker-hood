#include "FanFsm.h"
#include "FanFsmAction.h"
#include "FanState.h"
#include "FanStateFan1.h"
#include "FanStateFan1Off.h"
#include "FanStateFan2.h"
#include "FanStateFan2Off.h"
#include "FanStateFan3.h"
#include "FanStateFan3Off.h"

FanState* FanStateFan2Off::s_instance = 0;

FanState* FanStateFan2Off::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new FanStateFan2Off();
  }
  return s_instance;
}

void FanStateFan2Off::entry(FanFsm* fanFsm)
{
  FanState::entry(fanFsm);
  if (0 != fanFsm->action())
  {
    fanFsm->action()->actFanOff();
  }
}

const char* FanStateFan2Off::toString()
{
  return "FanStateFan2Off";
}

void FanStateFan2Off::fanLowEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan2::Instance());
}

void FanStateFan2Off::fanHighEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan2::Instance());
}

void FanStateFan2Off::fanToggleEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan2::Instance());
}
