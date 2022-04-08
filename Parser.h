#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

namespace zork
{

class Parser
{
public:
    Parser();
    ~Parser();

    // Command* commandConverter(string input);
    Command* operator()(string input); // Operator overloading, the brackets

    string showCommandsAsString();

private:
    CommandWords *commands;
};

}

#endif /*PARSER_H_*/
