#pragma once

#include <DbgCliCommand.h>

class FanFsmAction;
class DbgCli_Node;
class DbgTrace_Port;

class DbgCmd_FanToggleEvt : public DbgCli_Command
{
public:
  DbgCmd_FanToggleEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode);
  virtual ~DbgCmd_FanToggleEvt();

  void execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle);
  void printUsage();

private:
  FanFsmAction* m_fanFsmAction;

private:  // forbidden default functions
  DbgCmd_FanToggleEvt();                                            // default constructor
  DbgCmd_FanToggleEvt& operator = (const DbgCmd_FanToggleEvt& src); // assignment operator
  DbgCmd_FanToggleEvt(const DbgCmd_FanToggleEvt& src);              // copy constructor
};
