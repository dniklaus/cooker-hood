#pragma once

#include <DbgCliCommand.h>

class FanFsmAction;
class DbgCli_Node;

class DbgCmd_FanHigherEvt : public DbgCli_Command
{
public:
  DbgCmd_FanHigherEvt(FanFsmAction* fanFsmAction, DbgCli_Node* fanFsmEvtDbgCmdsNode);
  virtual ~DbgCmd_FanHigherEvt();

  void execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle);
  void printUsage();

private:
  FanFsmAction* m_fanFsmAction;

private:  // forbidden default functions
  DbgCmd_FanHigherEvt();                                            // default constructor
  DbgCmd_FanHigherEvt& operator = (const DbgCmd_FanHigherEvt& src); // assignment operator
  DbgCmd_FanHigherEvt(const DbgCmd_FanHigherEvt& src);              // copy constructor
};
