#ifndef COMMANDWORDS_H_
#define COMMANDWORDS_H_

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace zork
{

class CommandWords
{
public:
    CommandWords();
    bool isCommand(string myCommand);
    string showAllCommands();

private:
    // Define a static vector for our valid command words. We'll populate this in the class constructor
    static vector<string> validCommands;
};

}

#endif /*COMMANDWORDS_H_*/
