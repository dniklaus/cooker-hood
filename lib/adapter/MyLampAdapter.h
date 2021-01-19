/*
 * MyLampAdapter.h
 *
 *  Created on: 19.01.2021
 *      Author: Dieter Niklaus
 */

#ifndef LIB_ADAPTER_MYLAMPADAPTER_H_
#define LIB_ADAPTER_MYLAMPADAPTER_H_

#include <stdint.h>
#include <Indicator.h>

class MyLampAdapter: public AIndicatorAdapter
{
public:
  /**
   * Constructor.
   * @param index {0..4}, 0 : built-in LED, 1..4: Lamps 1..4
   */
  MyLampAdapter(unsigned int index = 0); 
  virtual ~MyLampAdapter();
  void notifyStatusChange(bool status);

private:
  void setLamp(bool isOn);
  const static uint32_t cLedPin;
  const static uint32_t cLamp1Pin;
  const static uint32_t cLamp2Pin;
  const static uint32_t cLamp3Pin;
  const static uint32_t cLamp4Pin;  
  uint32_t m_lampPin;

private:  // forbidden default functions
  MyLampAdapter(const MyLampAdapter &other) = delete;
  MyLampAdapter(MyLampAdapter &&other) = delete;
};

#endif /* LIB_ADAPTER_MYLAMPADAPTER_H_ */
