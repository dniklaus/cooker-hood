#include "FanFsm.h"
#include "FanFsmAction.h"
#include "FanState.h"
#include "FanStateFan1.h"
#include "FanStateFan1Off.h"
#include "FanStateFan2.h"
#include "FanStateFan2Off.h"
#include "FanStateFan3.h"
#include "FanStateFan3Off.h"

FanState* FanStateFan2::s_instance = 0;

FanState* FanStateFan2::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new FanStateFan2();
  }
  return s_instance;
}

void FanStateFan2::entry(FanFsm* fanFsm)
{
  FanState::entry(fanFsm);
  if (0 != fanFsm->action())
  {
    fanFsm->action()->actFan2();
  }
}

const char* FanStateFan2::toString()
{
  return "FanStateFan2";
}

void FanStateFan2::fanLowEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan1::Instance());
}

void FanStateFan2::fanHighEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan3::Instance());
}

void FanStateFan2::fanToggleEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan2Off::Instance());
}

void FanStateFan2::timerExpiredEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan2Off::Instance());
}
