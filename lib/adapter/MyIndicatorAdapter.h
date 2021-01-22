/*
 * MyIndicatorAdapter.h
 *
 *  Created on: 19.01.2021
 *      Author: Dieter Niklaus
 */

#ifndef LIB_ADAPTER_MYINDICATORADAPTER_H_
#define LIB_ADAPTER_MYINDICATORADAPTER_H_

#include <stdint.h>
#include <Indicator.h>

class MyIndicatorAdapter: public AIndicatorAdapter
{
public:
  /**
   * Constructor.
   * @param index {0..4}, 0 : built-in LED, 1..4: Lamps 1..4
   */
  MyIndicatorAdapter(unsigned int index = 0); 
  virtual ~MyIndicatorAdapter();
  void notifyStatusChange(bool status);

private:
  void setOutput(bool isOn);
  const static uint32_t cLedPin;
  const static uint32_t cRelay1Pin;
  const static uint32_t cRelay2Pin;
  const static uint32_t cRelay3Pin;
  const static uint32_t cRelay4Pin;  
  uint32_t m_outPin;

private:  // forbidden default functions
  MyIndicatorAdapter(const MyIndicatorAdapter &other) = delete;
  MyIndicatorAdapter(MyIndicatorAdapter &&other) = delete;
};

#endif /* LIB_ADAPTER_MYINDICATORADAPTER_H_ */
