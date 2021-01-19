/*
 * main.cpp
 *
 *  Created on: 19.01.2021
 *      Author: Dieter Niklaus
 */

#include <Arduino.h>

// PlatformIO libraries
#include <SerialCommand.h>  // pio lib install 173, lib details see https://github.com/kroimon/Arduino-SerialCommand
#include <SpinTimer.h>      // pio lib install 1699, lib details see https://github.com/dniklaus/spin-timer

// private libraries
#include <ProductDebug.h>

// local components (lib folder)
#include <Indicator.h>
#include <MyLampAdapter.h>

SerialCommand* sCmd = 0;

// pointer to indicator object for built in LED
Indicator* led = 0;

// pointers to indicator objects for 4 lamps
Indicator* lamp1 = 0;
Indicator* lamp2 = 0;
Indicator* lamp3 = 0;
Indicator* lamp4 = 0;

void setup()
{
  // setup basic debug environment (heap usage printer, trace ports & dbg cli)
  setupProdDebugEnv();

  // indicator LED
  led = new Indicator("led", "Built in LED.");
  led->assignAdapter(new MyLampAdapter());

  // 4 Lamps
  lamp1 = new Indicator("lamp1", "Lamp 1.");
  lamp1->clear();
  lamp1->assignAdapter(new MyLampAdapter(1));

  lamp2 = new Indicator("lamp2", "Lamp 2.");
  lamp2->clear();
  lamp2->assignAdapter(new MyLampAdapter(2));

  lamp3 = new Indicator("lamp3", "Lamp 3.");
  lamp3->clear();
  lamp3->assignAdapter(new MyLampAdapter(3));

  lamp4 = new Indicator("lamp4", "Lamp 4.");
  lamp4->clear();
  lamp4->assignAdapter(new MyLampAdapter(4));
}

void loop()
{
  if (0 != sCmd)
  {
    sCmd->readSerial();     // process serial commands
  }
  scheduleTimers();         // process Timers
}
