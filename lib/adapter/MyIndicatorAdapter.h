/*
 * MyIndicatorAdapter.h
 *
 *  Created on: 19.01.2021
 *      Author: Dieter Niklaus
 */

#ifndef LIB_ADAPTER_MYINDICATORADAPTER_H_
#define LIB_ADAPTER_MYINDICATORADAPTER_H_

#include <Indicator.h>

class MyIndicatorAdapter: public AIndicatorAdapter
{
public:
  /**
   * Constructor.
   * @param outPin Output pin.
   */
  MyIndicatorAdapter(int outPin); 
  virtual ~MyIndicatorAdapter();
  void notifyStatusChange(bool status);

private:
  void setOutput(bool isOn);
  int m_outPin;

private:  // forbidden default functions
  MyIndicatorAdapter(const MyIndicatorAdapter &other) = delete;
  MyIndicatorAdapter(MyIndicatorAdapter &&other) = delete;
};

#endif /* LIB_ADAPTER_MYINDICATORADAPTER_H_ */
