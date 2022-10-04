#pragma once

class FanState;
class FanFsmAction;
class SpinTimer;

class FanFsm
{
public:
  FanFsm(FanFsmAction* action);
  virtual ~FanFsm();

  FanFsmAction* action();

  void changeState(FanState* newState);
  FanState* state();
  FanState* prevState();

  void fanLowEvent();
  void fanHighEvent();
  void fanToggleEvent();
  void timerStartEvent();
  void timerExpiredEvent();

private:
  FanState* m_state;
  FanState* m_prevState;
  FanFsmAction* m_action;
  SpinTimer* m_timer;
  static const unsigned long c_fanOffTimeMillis;

private:  // forbidden default functions
  FanFsm();                               // default constructor
  FanFsm(const FanFsm& src);              // copy constructor
  FanFsm& operator = (const FanFsm& src); // assignment operator
};
