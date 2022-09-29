
/*
 * MuxedIndicatorPinAdapter.cpp
 *
 *  Created on: 19.09.2022
 *      Author: nid
 */

#include <Arduino.h>
#include <MuxedIndicatorPinAdapter.h>

MuxedIndicatorPinAdapter::MuxedIndicatorPinAdapter(Indicator* enabler, int outPin)
: m_enabler(enabler)
, m_outPin(outPin)
{ }

MuxedIndicatorPinAdapter::~MuxedIndicatorPinAdapter()
{ }

void MuxedIndicatorPinAdapter::setPinConfig()
{
  // initialize built in LED pin as output
  pinMode(m_outPin, OUTPUT);

  // switch LED off
  setOutput(false);
}

void MuxedIndicatorPinAdapter::notifyStatusChange(bool status)
{
  setOutput(status);
}

void MuxedIndicatorPinAdapter::setOutput(bool isOn)
{
#if defined(ESP8266) or defined(NRF52)
  // the built-in LED logic on ESP8266 and NRF52 modules are inverted!
  isOn = !isOn;
#endif
  digitalWrite(m_outPin, isOn);
}
