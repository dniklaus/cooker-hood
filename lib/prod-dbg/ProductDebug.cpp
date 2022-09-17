/*
 * ProductDebug.cpp
 *
 *  Created on: 19.01.2021
 *      Author: Dieter Niklaus
 */

#include <Arduino.h>
#include <AppDebug.h>
#include "ProductDebug.h"

void setupProdDebugEnv()
{
  setupDebugEnv('\0');

  Serial.println();
  Serial.println("---------------------------------------------");
  Serial.println("Hello from lights-on controller application!");
  Serial.println("---------------------------------------------");
  Serial.println();
}
