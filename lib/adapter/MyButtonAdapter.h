/*
 * MyButtonAdapter.h
 *
 *  Created on: 17.02.2020
 *      Author: dev
 */

#pragma once

#include <Button.h>

class DbgTrace_Port;
class MyButtonAdapter : public ButtonAdapter
{
public:
  MyButtonAdapter(Indicator* indicator);
  virtual ~MyButtonAdapter();

  void notifyStatusChanged(bool isActive);

private:
  Indicator* m_indicator;
  DbgTrace_Port* m_trPort;

private:  // forbidden functions
  MyButtonAdapter();                                        // default constructor
  MyButtonAdapter(const MyButtonAdapter& src);              // copy constructor
  MyButtonAdapter& operator = (const MyButtonAdapter& src); // assignment operator
};
