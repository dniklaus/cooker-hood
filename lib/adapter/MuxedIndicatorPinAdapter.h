#pragma once

#include <Indicator.h>

class Indicator;

class MuxedIndicatorPinAdapter: public AIndicatorAdapter
{
public:
  MuxedIndicatorPinAdapter(Indicator* enabler, int outPin); 
  virtual ~MuxedIndicatorPinAdapter();
  void notifyStatusChange(bool status);

private:
  void setPinConfig();
  void setOutput(bool isOn);

private:
  Indicator* m_enabler;
  uint32_t m_outPin;

private:  // forbidden default functions
  MuxedIndicatorPinAdapter();                                           // default constructor
  MuxedIndicatorPinAdapter(const MuxedIndicatorPinAdapter &other) = delete;
  MuxedIndicatorPinAdapter(MuxedIndicatorPinAdapter &&other) = delete;
};
