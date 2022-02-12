#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

class Parser
{

public:
    Parser();
    Command* getCommand();
    void showCommands();

private:
	CommandWords *commands;
};

#endif /*PARSER_H_*/
