#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

class Parser
{
public:
    Parser();
    ~Parser();
    Command* commandConverter(string input);
    string showCommandsAsString();

private:
	CommandWords *commands;
};

#endif /*PARSER_H_*/
