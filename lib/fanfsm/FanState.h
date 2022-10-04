#pragma once

class FanFsm;

class FanState
{
protected:
  FanState() { }

public:
  virtual ~FanState() { }

  virtual void fanLowEvent(FanFsm* fanFsm) { }
  virtual void fanHighEvent(FanFsm* fanFsm) { }
  virtual void fanToggleEvent(FanFsm* fanFsm) { }
  
  virtual void timerExpiredEvent(FanFsm* fanFsm) { }
  
  virtual void entry(FanFsm* fanFsm);
  
  virtual const char* toString() = 0;

private:  // forbidden default functions
  FanState(const FanState& src);              // copy constructor
  FanState& operator = (const FanState& src); // assignment operator
};
