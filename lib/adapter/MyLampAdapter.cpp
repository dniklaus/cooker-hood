/*
 * MyLampAdapter.cpp
 *
 *  Created on: 04.11.2019
 *      Author: nid
 */

#include <Arduino.h>
#include "MyLampAdapter.h"

// Seeed Studio Relais Shield v3.0 Pinout
const uint32_t MyLampAdapter::cLamp1Pin = 7;
const uint32_t MyLampAdapter::cLamp2Pin = 6;
const uint32_t MyLampAdapter::cLamp3Pin = 5;
const uint32_t MyLampAdapter::cLamp4Pin = 4;

const uint32_t MyLampAdapter::cLedPin = LED_BUILTIN;  

MyLampAdapter::MyLampAdapter(unsigned int index /* = 0 */)
: m_lampPin((index == 1) ? cLamp1Pin : (index == 2) ? cLamp2Pin : (index == 3) ? cLamp3Pin : (index == 4) ? cLamp4Pin : cLedPin)
{
  // initialize built in LED pin as output
  pinMode(m_lampPin, OUTPUT);

  // switch LED off
  setLamp(false);
}

MyLampAdapter::~MyLampAdapter()
{ }

void MyLampAdapter::notifyStatusChange(bool status)
{
  setLamp(status);
}

void MyLampAdapter::setLamp(bool isOn)
{
#if defined(ESP8266) or defined(NRF52)
  // the built-in LED logic on ESP8266 and NRF52 modules are inverted!
  isOn = !isOn;
#endif
  digitalWrite(m_lampPin, isOn);
}
