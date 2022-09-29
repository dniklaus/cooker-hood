/*
 * ButtonEdgeDetector.cpp
 *
 *  Created on: 17.02.2020
 *      Author: dev
 */

#include <DbgTracePort.h>
#include <DbgTraceLevel.h>
#include <Button.h>
#include <ButtonEdgeDetector.h>

ButtonEdgeDetector::ButtonEdgeDetector()
{ }

ButtonEdgeDetector::~ButtonEdgeDetector()
{ }

void ButtonEdgeDetector::onEdge(bool newState)
{
  if (0 != button())
  {
    if (0 != button()->adapter())
    {
      button()->adapter()->notifyStatusChanged(newState);
    }
  }
}
