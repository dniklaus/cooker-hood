#pragma once

#include "FanState.h"

class FanStateFan1Off : public FanState
{
protected:
  FanStateFan1Off() { }

public:
  static FanState* Instance();
  virtual ~FanStateFan1Off() { }

  void fanLowEvent(FanFsm* fanFsm) { }
  void fanHighEvent(FanFsm* fanFsm);
  void fanToggleEvent(FanFsm* fanFsm);
  void timerExpiredEvent(FanFsm* fanFsm) { }
  
  void entry(FanFsm* fanFsm);
  
  const char* toString();

private:
  static FanState* s_instance;

private:  // forbidden default functions
  FanStateFan1Off(const FanStateFan1Off& src);              // copy constructor
  FanStateFan1Off& operator = (const FanStateFan1Off& src); // assignment operator
};
