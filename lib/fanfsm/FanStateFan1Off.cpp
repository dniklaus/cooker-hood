#include "FanFsm.h"
#include "FanFsmAction.h"
#include "FanState.h"
#include "FanStateFan1.h"
#include "FanStateFan1Off.h"
#include "FanStateFan2.h"
#include "FanStateFan2Off.h"
#include "FanStateFan3.h"
#include "FanStateFan3Off.h"

FanState* FanStateFan1Off::s_instance = 0;

FanState* FanStateFan1Off::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new FanStateFan1Off();
  }
  return s_instance;
}

void FanStateFan1Off::entry(FanFsm* fanFsm)
{
  FanState::entry(fanFsm);
  if (0 != fanFsm->action())
  {
    fanFsm->action()->actFanOff();
  }
}

const char* FanStateFan1Off::toString()
{
  return "FanStateFan1Off";
}

void FanStateFan1Off::fanLowEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan1::Instance());
}

void FanStateFan1Off::fanHighEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan1::Instance());
}

void FanStateFan1Off::fanToggleEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan1::Instance());
}
