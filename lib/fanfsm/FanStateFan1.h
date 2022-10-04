#pragma once

#include "FanState.h"

class FanStateFan1 : public FanState
{
protected:
  FanStateFan1() { }

public:
  static FanState* Instance();
  virtual ~FanStateFan1() { }

  void fanLowEvent(FanFsm* fanFsm);
  void fanHighEvent(FanFsm* fanFsm);
  void fanToggleEvent(FanFsm* fanFsm);
  void timerExpiredEvent(FanFsm* fanFsm);
  
  void entry(FanFsm* fanFsm);
  
  const char* toString();

private:
  static FanState* s_instance;

private:  // forbidden default functions
  FanStateFan1(const FanStateFan1& src);              // copy constructor
  FanStateFan1& operator = (const FanStateFan1& src); // assignment operator
};
