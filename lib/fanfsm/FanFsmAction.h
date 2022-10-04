#pragma once

class DbgTrace_Port;

class FanFsmAction
{
protected:
  FanFsmAction();

public:
  virtual ~FanFsmAction();

  DbgTrace_Port* trPort();

  virtual void actFan1() = 0;
  virtual void actFan2() = 0;
  virtual void actFan3() = 0;
  virtual void actFanOff() = 0;

private:
  DbgTrace_Port* m_trPort;

private:  // forbidden default functions
  FanFsmAction(const FanFsmAction& src);              // copy constructor
  FanFsmAction& operator = (const FanFsmAction& src); // assignment operator
};
