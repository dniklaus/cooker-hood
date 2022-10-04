#pragma once

#include <DbgCliCommand.h>

class FanFsmAction;
class DbgCli_Node;
class DbgTrace_Port;

class DbgCmd_FanLowerEvt : public DbgCli_Command
{
public:
  DbgCmd_FanLowerEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode);
  virtual ~DbgCmd_FanLowerEvt();

  void execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle);
  void printUsage();

private:
  FanFsmAction* m_fanFsmAction;

private:  // forbidden default functions
  DbgCmd_FanLowerEvt();                                           // default constructor
  DbgCmd_FanLowerEvt& operator = (const DbgCmd_FanLowerEvt& src); // assignment operator
  DbgCmd_FanLowerEvt(const DbgCmd_FanLowerEvt& src);              // copy constructor
};
