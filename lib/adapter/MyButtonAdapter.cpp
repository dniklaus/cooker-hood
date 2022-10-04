/*
 * MyButtonAdapter.cpp
 *
 *  Created on: 17.02.2020
 *      Author: dev
 */
#include <Arduino.h>
#include <DbgTracePort.h>
#include <DbgTraceLevel.h>
#include <DbgCliTopic.h>
#include <Indicator.h>
#include <MyButtonAdapter.h>

MyButtonAdapter::MyButtonAdapter(Indicator* indicator)
: m_indicator(indicator)
, m_trPort(new DbgTrace_Port(indicator->dbgCliTopic()->getNodeName(), DbgTrace_Level::info))
{ }

MyButtonAdapter::~MyButtonAdapter()
{ 
  delete m_trPort;
  m_trPort = 0;
}

void MyButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (0 != m_indicator)
  {
    if (isActive)
    {
      TR_PRINTF(m_trPort, DbgTrace_Level::info, "Button pressed")
      switch (m_indicator->getState())
      {
        case Indicator::EIndState::off:
          m_indicator->set();
          break;
        default:
          m_indicator->clear();
          break;
      }
    }
  }
}
