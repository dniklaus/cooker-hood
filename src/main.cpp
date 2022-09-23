/*
 * main.cpp
 *
 *  Created on: 18.09.2022
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
#include <Button.h>
#include <EdgeDetector.h>
#include <DetectorStrategy.h>
#include <MuxedPinSupervisor.h>

SerialCommand* sCmd = 0;

// pointer to indicator object for built in LED
Indicator* led = 0;

// pointers to indicator objects for 4 lamps
Indicator* lamprelay = 0;
Indicator* fan1relay = 0;
Indicator* fan2relay = 0;
Indicator* fan3relay = 0;

Indicator* lampLed   = 0;
Indicator* fan1Led   = 0;
Indicator* fan2Led   = 0;
Indicator* fan3Led   = 0;
Indicator* timerLed  = 0;
Indicator* ledEnable = 0;

Button* lampButton   = 0;
Button* fanLoButton  = 0;
Button* fanTgButton  = 0;
Button* fanHiButton  = 0;
Button* timerButton  = 0;

void setup()
{
  // setup basic debug environment (heap usage printer, trace ports & dbg cli)
  setupProdDebugEnv();

  // indicator LED
  led = new Indicator("led", "Built in LED.");
  led->assignAdapter(new MyIndicatorAdapter());

  // 4 Relays
  lamprelay = new Indicator("lampr", "Relay 1 - Lamp.");
  lamprelay->clear();
  lamprelay->assignAdapter(new MyIndicatorAdapter(1));

  fan1relay = new Indicator("fan1r", "Relay 2 - Fan 1.");
  fan1relay->clear();
  fan1relay->assignAdapter(new MyIndicatorAdapter(2));

  fan2relay = new Indicator("fan2r", "Relay 3 - Fan 2.");
  fan2relay->clear();
  fan2relay->assignAdapter(new MyIndicatorAdapter(3));

  fan3relay = new Indicator("fan3r", "Relay 4 - Fan 3.");
  fan3relay->clear();
  fan3relay->assignAdapter(new MyIndicatorAdapter(4));

  lampLed = new Indicator("lampl", "LED 1 - Lamp.");

  fan1Led = new Indicator("fan1l", "LED 2 - Fan 1.");

  fan2Led = new Indicator("fan2l", "LED 3 - Fan 2.");

  fan3Led = new Indicator("fan3l", "LED 4 - Fan 3.");

  timerLed = new Indicator("timerl", "LED 5 - Timer.");

  ledEnable = new Indicator("ledEn", "LED enable control.");
  ledEnable->blinkTimer()->start(50);
  ledEnable->blink();

  lampButton  = new Button(new MuxedPinSupervisor(ledEnable, 12), new ButtonEdgeDetector(), new MyButtonAdapter());
  fanLoButton = new Button(new MuxedPinSupervisor(ledEnable, 11), new ButtonEdgeDetector(), new MyButtonAdapter());
  fanTgButton = new Button(new MuxedPinSupervisor(ledEnable, 10), new ButtonEdgeDetector(), new MyButtonAdapter());
  fanHiButton = new Button(new MuxedPinSupervisor(ledEnable,  9), new ButtonEdgeDetector(), new MyButtonAdapter());
  timerButton = new Button(new MuxedPinSupervisor(ledEnable,  8), new ButtonEdgeDetector(), new MyButtonAdapter());
}

void loop()
{
  if (0 != sCmd)
  {
    sCmd->readSerial();     // process serial commands
  }
  scheduleTimers();         // process Timers
}
