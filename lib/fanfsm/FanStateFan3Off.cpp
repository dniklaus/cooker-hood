#include "FanFsm.h"
#include "FanFsmAction.h"
#include "FanState.h"
#include "FanStateFan1.h"
#include "FanStateFan1Off.h"
#include "FanStateFan2.h"
#include "FanStateFan2Off.h"
#include "FanStateFan3.h"
#include "FanStateFan3Off.h"

FanState* FanStateFan3Off::s_instance = 0;

FanState* FanStateFan3Off::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new FanStateFan3Off();
  }
  return s_instance;
}

void FanStateFan3Off::entry(FanFsm* fanFsm)
{
  FanState::entry(fanFsm);
  if (0 != fanFsm->action())
  {
    fanFsm->action()->actFanOff();
  }
}

const char* FanStateFan3Off::toString()
{
  return "FanStateFan3Off";
}

void FanStateFan3Off::fanLowEvent(FanFsm* fanFsm)
{

}

void FanStateFan3Off::fanHighEvent(FanFsm* fanFsm)
{

}

void FanStateFan3Off::fanToggleEvent(FanFsm* fanFsm)
{

}
