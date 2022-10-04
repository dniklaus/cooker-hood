#pragma once

#include <Button.h>

class FanFsm;
class DbgTrace_Port;

//-----------------------------------------------------------------------------

class MyFanLoButtonAdapter : public ButtonAdapter
{
public:
  MyFanLoButtonAdapter(FanFsm* fanFsm);
  virtual ~MyFanLoButtonAdapter() { }

  void notifyStatusChanged(bool isActive);

private:
  FanFsm* m_fanFsm;
  DbgTrace_Port* m_trPort;

private:  // forbidden functions
  MyFanLoButtonAdapter();                                             // default constructor
  MyFanLoButtonAdapter(const MyFanLoButtonAdapter& src);              // copy constructor
  MyFanLoButtonAdapter& operator = (const MyFanLoButtonAdapter& src); // assignment operator
};

//-----------------------------------------------------------------------------

class MyFanHiButtonAdapter : public ButtonAdapter
{
public:
  MyFanHiButtonAdapter(FanFsm* fanFsm);
  virtual ~MyFanHiButtonAdapter() { }

  void notifyStatusChanged(bool isActive);

private:
  FanFsm* m_fanFsm;
  DbgTrace_Port* m_trPort;

private:  // forbidden functions
  MyFanHiButtonAdapter();                                             // default constructor
  MyFanHiButtonAdapter(const MyFanHiButtonAdapter& src);              // copy constructor
  MyFanHiButtonAdapter& operator = (const MyFanHiButtonAdapter& src); // assignment operator
};

//-----------------------------------------------------------------------------

class MyFanTgButtonAdapter : public ButtonAdapter
{
public:
  MyFanTgButtonAdapter(FanFsm* fanFsm);
  virtual ~MyFanTgButtonAdapter() { }

  void notifyStatusChanged(bool isActive);

private:
  FanFsm* m_fanFsm;
  DbgTrace_Port* m_trPort;

private:  // forbidden functions
  MyFanTgButtonAdapter();                                             // default constructor
  MyFanTgButtonAdapter(const MyFanTgButtonAdapter& src);              // copy constructor
  MyFanTgButtonAdapter& operator = (const MyFanTgButtonAdapter& src); // assignment operator
};

//-----------------------------------------------------------------------------
class MyFanTimerButtonAdapter : public ButtonAdapter
{
public:
  MyFanTimerButtonAdapter(FanFsm* fanFsm);
  virtual ~MyFanTimerButtonAdapter() { }

  void notifyStatusChanged(bool isActive);

private:
  FanFsm* m_fanFsm;
  DbgTrace_Port* m_trPort;

private:  // forbidden functions
  MyFanTimerButtonAdapter();                                                // default constructor
  MyFanTimerButtonAdapter(const MyFanTimerButtonAdapter& src);              // copy constructor
  MyFanTimerButtonAdapter& operator = (const MyFanTimerButtonAdapter& src); // assignment operator
};
