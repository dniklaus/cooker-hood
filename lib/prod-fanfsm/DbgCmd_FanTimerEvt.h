#pragma once

#include <DbgCliCommand.h>

class FanFsmAction;
class DbgCli_Node;
class DbgTrace_Port;

class DbgCmd_FanTimerEvt : public DbgCli_Command
{
public:
  DbgCmd_FanTimerEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode);
  virtual ~DbgCmd_FanTimerEvt();

  void execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle);
  void printUsage();

private:
  FanFsmAction* m_fanFsmAction;

private:  // forbidden default functions
  DbgCmd_FanTimerEvt();                                           // default constructor
  DbgCmd_FanTimerEvt& operator = (const DbgCmd_FanTimerEvt& src); // assignment operator
  DbgCmd_FanTimerEvt(const DbgCmd_FanTimerEvt& src);              // copy constructor
};
