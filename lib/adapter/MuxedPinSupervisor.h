#pragma once

#include <Button.h>

class Indicator;

class MuxedPinSupervisor: public PinSupervisor
{
public:
  MuxedPinSupervisor(Indicator* inhibitor, int arduinoPin);
  virtual ~MuxedPinSupervisor();

  void setPinConfig();
  bool getPinState();

private:
  Indicator* m_inhibitor;
  int m_arduinoPin;

private:  // forbidden functions
  MuxedPinSupervisor();                                           // default constructor
  MuxedPinSupervisor(const MuxedPinSupervisor& src);              // copy constructor
  MuxedPinSupervisor& operator = (const MuxedPinSupervisor& src); // assignment operator
};
