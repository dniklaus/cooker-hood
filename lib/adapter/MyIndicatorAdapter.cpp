/*
 * MyIndicatorAdapter.cpp
 *
 *  Created on: 04.11.2019
 *      Author: nid
 */

#include <Arduino.h>
#include "MyIndicatorAdapter.h"

MyIndicatorAdapter::MyIndicatorAdapter(int outPin)
: m_outPin(outPin)
{
  // initialize built in LED pin as output
  pinMode(m_outPin, OUTPUT);

  // switch LED off
  setOutput(false);
}

MyIndicatorAdapter::~MyIndicatorAdapter()
{ }

void MyIndicatorAdapter::notifyStatusChange(bool status)
{
  setOutput(status);
}

void MyIndicatorAdapter::setOutput(bool isOn)
{
#if defined(ESP8266) or defined(NRF52)
  // the built-in LED logic on ESP8266 and NRF52 modules are inverted!
  isOn = !isOn;
#endif
  digitalWrite(m_outPin, isOn);
}
