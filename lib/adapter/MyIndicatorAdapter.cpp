/*
 * MyIndicatorAdapter.cpp
 *
 *  Created on: 04.11.2019
 *      Author: nid
 */

#include <Arduino.h>
#include "MyIndicatorAdapter.h"

// Seeed Studio Relais Shield v3.0 Pinout
const uint32_t MyIndicatorAdapter::cRelay1Pin = 7;
const uint32_t MyIndicatorAdapter::cRelay2Pin = 6;
const uint32_t MyIndicatorAdapter::cRelay3Pin = 5;
const uint32_t MyIndicatorAdapter::cRelay4Pin = 4;

const uint32_t MyIndicatorAdapter::cLedPin = LED_BUILTIN;  

MyIndicatorAdapter::MyIndicatorAdapter(unsigned int index /* = 0 */)
: m_outPin((index == 1) ? cRelay1Pin : (index == 2) ? cRelay2Pin : (index == 3) ? cRelay3Pin : (index == 4) ? cRelay4Pin : cLedPin)
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
