#pragma once

#include <FanState.h>

class FanStateFan3 : public FanState
{
protected:
  FanStateFan3() { }

public:
  static FanState* Instance();
  virtual ~FanStateFan3() { }

  void fanLowEvent(FanFsm* fanFsm);
  void fanHighEvent(FanFsm* fanFsm) { }
  void fanToggleEvent(FanFsm* fanFsm);
  void timerExpiredEvent(FanFsm* fanFsm);
  
  void entry(FanFsm* fanFsm);
  
  const char* toString();

private:
  static FanState* s_instance;

private:  // forbidden default functions
  FanStateFan3(const FanStateFan3& src);              // copy constructor
  FanStateFan3& operator = (const FanStateFan3& src); // assignment operator
};
