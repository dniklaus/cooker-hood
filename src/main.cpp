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

// local components (lib folder)
#include <Indicator.h>
#include <Button.h>
#include <EdgeDetector.h>
#include <DetectorStrategy.h>

// private libraries
#include <ProductDebug.h>
#include <FanFsm.h>
#include <MyFanFsmAction.h>
#include <MyIndicatorAdapter.h>
#include <ButtonEdgeDetector.h>
#include <MyButtonAdapter.h>
#include <MyFanButtonAdapter.h>
#include <MuxedPinSupervisor.h>
#include <MuxedIndicatorPinAdapter.h>

const int cLampRelayPin =  7;
const int cFan1RelayPin =  6;
const int cFan2RelayPin =  5;
const int cFan3RelayPin =  4;
const int cLedEnablePin =  3;
const int cLampLedPin   = 12;
const int cFan1LedPin   = 11;
const int cFan2LedPin   = 10;
const int cFan3LedPin   =  9;
const int cTimerLedPin  =  8;

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

FanFsm* fanFsm = 0;

void setup()
{
  // setup basic debug environment (heap usage printer, trace ports & dbg cli)
  setupProdDebugEnv();

  // indicator LED
  led = new Indicator("led", "Built in LED.");
  led->assignAdapter(new MyIndicatorAdapter(LED_BUILTIN));

  // 4 Relays
  lamprelay = new Indicator("lampr", "Relay 1 - Lamp.");
  lamprelay->clear();
  lamprelay->assignAdapter(new MyIndicatorAdapter(cLampRelayPin));

  fan1relay = new Indicator("fan1r", "Relay 2 - Fan 1.");
  fan1relay->clear();
  fan1relay->assignAdapter(new MyIndicatorAdapter(cFan1RelayPin));

  fan2relay = new Indicator("fan2r", "Relay 3 - Fan 2.");
  fan2relay->clear();
  fan2relay->assignAdapter(new MyIndicatorAdapter(cFan2RelayPin));

  fan3relay = new Indicator("fan3r", "Relay 4 - Fan 3.");
  fan3relay->clear();
  fan3relay->assignAdapter(new MyIndicatorAdapter(cFan3RelayPin));

  ledEnable = new Indicator("ledEn", "LED enable control.");
  ledEnable->blinkTimer()->start(1000);
  ledEnable->clear();  // TODO: make this blink later (first: disable LEDs / enable buttons)
  ledEnable->assignAdapter(new MyIndicatorAdapter(cLedEnablePin));

  lampLed = new Indicator("lampl", "LED 1 - Lamp.");
  lampLed->clear();
  lampLed->assignAdapter(new MuxedIndicatorPinAdapter(ledEnable, cLampLedPin));

  fan1Led = new Indicator("fan1l", "LED 2 - Fan 1.");
  fan1Led->clear();
  fan1Led->assignAdapter(new MuxedIndicatorPinAdapter(ledEnable, cFan1LedPin));

  fan2Led = new Indicator("fan2l", "LED 3 - Fan 2.");
  fan2Led->clear();
  fan2Led->assignAdapter(new MuxedIndicatorPinAdapter(ledEnable, cFan2LedPin));

  fan3Led = new Indicator("fan3l", "LED 4 - Fan 3.");
  fan3Led->clear();
  fan3Led->assignAdapter(new MuxedIndicatorPinAdapter(ledEnable, cFan3LedPin));

  timerLed = new Indicator("timerl", "LED 5 - Timer.");
  timerLed->clear();
  timerLed->assignAdapter(new MuxedIndicatorPinAdapter(ledEnable, cTimerLedPin));

  fanFsm = new FanFsm(new MyFanFsmAction(fan1relay, fan2relay, fan2relay));

  lampButton  = new Button(new MuxedPinSupervisor(ledEnable, cLampLedPin),  new ButtonEdgeDetector(), new MyButtonAdapter(lamprelay));
  fanLoButton = new Button(new MuxedPinSupervisor(ledEnable, cFan1LedPin),  new ButtonEdgeDetector(), new MyFanLoButtonAdapter(fanFsm));
  fanTgButton = new Button(new MuxedPinSupervisor(ledEnable, cFan2LedPin),  new ButtonEdgeDetector(), new MyFanTgButtonAdapter(fanFsm));
  fanHiButton = new Button(new MuxedPinSupervisor(ledEnable, cFan3LedPin),  new ButtonEdgeDetector(), new MyFanHiButtonAdapter(fanFsm));
  timerButton = new Button(new MuxedPinSupervisor(ledEnable, cTimerLedPin), new ButtonEdgeDetector(), new MyFanTimerButtonAdapter(fanFsm));
}

void loop()
{
  if (0 != sCmd)
  {
    sCmd->readSerial();     // process serial commands
  }
  scheduleTimers();         // process Timers
}
