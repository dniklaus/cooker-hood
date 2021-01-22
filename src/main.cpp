/*
 * main.cpp
 *
 *  Created on: 19.01.2021
 *      Author: Dieter Niklaus
 */

#include <Arduino.h>

// PlatformIO libraries
#include <SerialCommand.h>  // pio lib install 173, lib details see https://github.com/kroimon/Arduino-SerialCommand
#include <SpinTimer.h>      // pio lib install 11599, lib details see https://github.com/dniklaus/spin-timer

// private libraries
#include <ProductDebug.h>

// local components (lib folder)
#include <Indicator.h>
#include <MyIndicatorAdapter.h>

SerialCommand* sCmd = 0;

// pointer to indicator object for built in LED
Indicator* led = 0;

// pointers to indicator objects for 4 lamps
Indicator* lamp     = 0;
Indicator* pwrcycle = 0;
Indicator* reset   = 0;
Indicator* relay4   = 0;

void setup()
{
  // setup basic debug environment (heap usage printer, trace ports & dbg cli)
  setupProdDebugEnv();

  // indicator LED
  led = new Indicator("led", "Built in LED.");
  led->assignAdapter(new MyIndicatorAdapter());

  // 4 Lamps
  lamp = new Indicator("lamp", "Relay 1 - Lamp.");
  lamp->clear();
  lamp->assignAdapter(new MyIndicatorAdapter(1));

  pwrcycle = new Indicator("pwrcycle", "Relay 2 - Power Cycle.");
  pwrcycle->clear();
  pwrcycle->assignAdapter(new MyIndicatorAdapter(2));

  reset = new Indicator("reset", "Relay 3 - Reset Button.");
  reset->clear();
  reset->assignAdapter(new MyIndicatorAdapter(3));

  relay4 = new Indicator("relay4", "Relay 4.");
  relay4->clear();
  relay4->assignAdapter(new MyIndicatorAdapter(4));
}

void loop()
{
  if (0 != sCmd)
  {
    sCmd->readSerial();     // process serial commands
  }
  scheduleTimers();         // process Timers
}
