#pragma once

#include "FanState.h"

class FanStateFan2Off : public FanState
{
protected:
  FanStateFan2Off() { }

public:
  static FanState* Instance();
  virtual ~FanStateFan2Off() { }

  void fanLowEvent(FanFsm* fanFsm);
  void fanHighEvent(FanFsm* fanFsm);
  void fanToggleEvent(FanFsm* fanFsm);
  void timerExpiredEvent(FanFsm* fanFsm) { }
  
  void entry(FanFsm* fanFsm);
  
  const char* toString();

private:
  static FanState* s_instance;

private:  // forbidden default functions
  FanStateFan2Off(const FanStateFan2Off& src);              // copy constructor
  FanStateFan2Off& operator = (const FanStateFan2Off& src); // assignment operator
};
