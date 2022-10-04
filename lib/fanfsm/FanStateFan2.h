#pragma once

#include "FanState.h"

class FanStateFan2 : public FanState
{
protected:
  FanStateFan2() { }

public:
  static FanState* Instance();
  virtual ~FanStateFan2() { }

  void fanLowEvent(FanFsm* fanFsm);
  void fanHighEvent(FanFsm* fanFsm);
  void fanToggleEvent(FanFsm* fanFsm);
  void timerExpiredEvent(FanFsm* fanFsm);
  
  void entry(FanFsm* fanFsm);
  
  const char* toString();

private:
  static FanState* s_instance;

private:  // forbidden default functions
  FanStateFan2(const FanStateFan2& src);              // copy constructor
  FanStateFan2& operator = (const FanStateFan2& src); // assignment operator
};
