#include "FanFsm.h"
#include "FanFsmAction.h"
#include "FanState.h"
#include "FanStateFan1.h"
#include "FanStateFan1Off.h"
#include "FanStateFan2.h"
#include "FanStateFan2Off.h"
#include "FanStateFan3.h"
#include "FanStateFan3Off.h"

FanState* FanStateFan1::s_instance = 0;

FanState* FanStateFan1::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new FanStateFan1();
  }
  return s_instance;
}

void FanStateFan1::entry(FanFsm* fanFsm)
{
  FanState::entry(fanFsm);
  if (0 != fanFsm->action())
  {
    fanFsm->action()->actFan1();
  }
}

const char* FanStateFan1::toString()
{
  return "FanStateFan1";
}

void FanStateFan1::fanLowEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan1Off::Instance());
}

void FanStateFan1::fanHighEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan2::Instance());
}

void FanStateFan1::fanToggleEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan1Off::Instance());
}

void FanStateFan1::timerExpiredEvent(FanFsm* fanFsm)
{
  fanFsm->changeState(FanStateFan1Off::Instance());
}
