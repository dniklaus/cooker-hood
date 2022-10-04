#include "FanFsm.h"
#include "FanFsmAction.h"
#include "FanState.h"
#include "FanStateFan1.h"
#include "FanStateFan1Off.h"
#include "FanStateFan2.h"
#include "FanStateFan2Off.h"
#include "FanStateFan3.h"
#include "FanStateFan3Off.h"

FanState* FanStateFan3::s_instance = 0;

FanState* FanStateFan3::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new FanStateFan3();
  }
  return s_instance;
}

void FanStateFan3::entry(FanFsm* fanFsm)
{
  FanState::entry(fanFsm);
  if (0 != fanFsm->action())
  {
    fanFsm->action()->actFan3();
  }
}

const char* FanStateFan3::toString()
{
  return "FanStateFan3";
}

void FanStateFan3::fanLowEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan2::Instance());
}

void FanStateFan3::fanToggleEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan3Off::Instance());
}

void FanStateFan3::timerExpiredEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan3Off::Instance());
}
