#include <SpinTimer.h>
#include <DbgTracePort.h>
#include <DbgTraceLevel.h>

#include "FanFsm.h"
#include "FanFsmAction.h"
#include "FanState.h"
#include "FanStateFan1.h"
#include "FanStateFan1Off.h"
#include "FanStateFan2.h"
#include "FanStateFan2Off.h"
#include "FanStateFan3.h"
#include "FanStateFan3Off.h"

class FanSpinTimerAction : public SpinTimerAction
{
private:
  FanFsm* m_fanFsm;

public:
  FanSpinTimerAction(FanFsm* fanFsm)
  : m_fanFsm(fanFsm)
  { }

  virtual ~FanSpinTimerAction() { }

  void timeExpired()
  {
    if (0 != m_fanFsm)
    {
      m_fanFsm->timerExpiredEvent();
    }
  }
};

//-----------------------------------------------------------------------------

const unsigned long FanFsm::c_fanOffTimeMillis = 1800000;  // 30 Minutes
// const unsigned long FanFsm::c_fanOffTimeMillis = 30000;  // 30 Seconds

FanFsm::FanFsm(FanFsmAction* action)
: m_state(FanStateFan1Off::Instance())
, m_prevState(FanStateFan1Off::Instance())
, m_action(action)
, m_timer(new SpinTimer(FanFsm::c_fanOffTimeMillis, new FanSpinTimerAction(this), SpinTimer::IS_NON_RECURRING, SpinTimer::IS_NON_AUTOSTART))
{ 
  if (0 != action)
  {
    action->attachFsm(this);
  }
}

FanFsm::~FanFsm()
{ }

FanFsmAction* FanFsm::action()
{
  return m_action;
}

SpinTimer* FanFsm::timer()
{
  return m_timer;
}

void FanFsm::changeState(FanState* newState)
{
  m_prevState = m_state;
  m_state = newState;

  if (0 != newState)
  {
    newState->entry(this);
  }
}

FanState* FanFsm::state()
{
  return m_state;
}

FanState* FanFsm::prevState()
{
  return m_prevState;
}

void FanFsm::fanLowEvent()
{
  if (0 != action())
  {
    TR_PRINTF(action()->trPort(), DbgTrace_Level::info, "Fan Fsm Evt: Fan Lower Button pressed");
  }
  if (0 != m_state)
  {
    m_state->fanLowEvent(this);
  }
}

void FanFsm::fanHighEvent()
{
  if (0 != action())
  {
    TR_PRINTF(action()->trPort(), DbgTrace_Level::info, "Fan Fsm Evt: Fan Higher Button pressed");
  }
  if (0 != m_state)
  {
    m_state->fanHighEvent(this);
  }
}

void FanFsm::fanToggleEvent()
{
  if (0 != action())
  {
    TR_PRINTF(action()->trPort(), DbgTrace_Level::info, "Fan Fsm Evt: Fan Toggle Button pressed");
  }
  if (0 != m_state)
  {
    m_state->fanToggleEvent(this);
  }
}
  
void FanFsm::timerStartEvent(unsigned long fanOffTimeMillis /* = c_fanOffTimeMillis */)
{
  if (0 != action())
  {
    TR_PRINTF(action()->trPort(), DbgTrace_Level::info, "Fan Fsm Evt: Fan Timer Button pressed");
  }
  if (m_state == FanStateFan1::Instance() ||
      m_state == FanStateFan2::Instance() ||
      m_state == FanStateFan3::Instance()   )
  {
    m_timer->start(fanOffTimeMillis);
    if (0 != action())
    {
      TR_PRINTF(action()->trPort(), DbgTrace_Level::info, "Fan Fsm Evt: Timer started with %lu ms", fanOffTimeMillis);
    }
  }
  else if (0 != action())
  {
    TR_PRINTF(action()->trPort(), DbgTrace_Level::info, "Fan Fsm Evt: Timer not started (inhibit by state %s)", 
                                  m_state->toString());
  }
}

void FanFsm::timerExpiredEvent()
{
  if (0 != action())
  {
    TR_PRINTF(action()->trPort(), DbgTrace_Level::info, "Fan Fsm Evt: Fan Timer expired");
  }
  if (0 != m_state)
  {
    m_state->timerExpiredEvent(this);
  }
}
