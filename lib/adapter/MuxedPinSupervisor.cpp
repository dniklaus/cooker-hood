#include <MuxedPinSupervisor.h>
#include <Indicator.h>


/*
 * MuxedPinSupervisor.cpp
 *
 *  Created on: 25.01.2018
 *      Author: niklaudi
 */


#include <Arduino.h>
#include <Indicator.h>
#include <MuxedPinSupervisor.h>

MuxedPinSupervisor::MuxedPinSupervisor(Indicator* inhibitor, int arduinoPin)
: PinSupervisor(PinSupervisor::IS_NEG_LOGIC)
, m_inhibitor(inhibitor)
, m_arduinoPin(arduinoPin)
{ }

MuxedPinSupervisor::~MuxedPinSupervisor()
{ }

void MuxedPinSupervisor::setPinConfig()
{
  pinMode(m_arduinoPin, INPUT);
  digitalWrite(m_arduinoPin, isButtonNegativeLogic() ? HIGH : LOW); // pull
}

bool MuxedPinSupervisor::getPinState()
{
  bool state = false;
  if ((0 != m_inhibitor) && !m_inhibitor->status())
  {
    if (0 <= m_arduinoPin)
    {
      setPinConfig();
      state = digitalRead(m_arduinoPin);
    }
  }
  return state;
}