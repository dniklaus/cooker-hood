#pragma once

#include "FanState.h"

class FanStateFan3Off : public FanState
{
protected:
  FanStateFan3Off() { }

public:
  static FanState* Instance();
  virtual ~FanStateFan3Off() { }

  void fanLowEvent(FanFsm* fanFsm);
  void fanHighEvent(FanFsm* fanFsm);
  void fanToggleEvent(FanFsm* fanFsm);
  void timerExpiredEvent(FanFsm* fanFsm) { }
  
  void entry(FanFsm* fanFsm);
  
  const char* toString();

private:
  static FanState* s_instance;

private:  // forbidden default functions
  FanStateFan3Off(const FanStateFan3Off& src);              // copy constructor
  FanStateFan3Off& operator = (const FanStateFan3Off& src); // assignment operator
};
