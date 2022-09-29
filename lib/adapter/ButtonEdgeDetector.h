/*
 * ButtonEdgeDetector.h
 *
 *  Created on: 17.02.2020
 *      Author: dev
 */

#ifndef LIB_ADAPTER_BUTTONEDGEDETECTOR_H_
#define LIB_ADAPTER_BUTTONEDGEDETECTOR_H_

#include <EdgeDetector.h>
#include <DetectorStrategy.h>

class ButtonEdgeDetector : public EdgeDetector
{
public:
  ButtonEdgeDetector();
  virtual ~ButtonEdgeDetector();

  void onEdge(bool newState);

private:  // forbidden functions
  ButtonEdgeDetector(const ButtonEdgeDetector& src);              // copy constructor
  ButtonEdgeDetector& operator = (const ButtonEdgeDetector& src); // assignment operator
};

#endif /* LIB_ADAPTER_BUTTONEDGEDETECTOR_H_ */
