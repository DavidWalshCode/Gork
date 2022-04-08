#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
using std::string;

namespace zork
{

class Command
{
public:
    Command(string firstWord, string secondWord);
    Command(const Command& command);

    string getCommandWord();
    string getSecondWord();
    bool isUnknown();
    bool hasSecondWord();

private:
    string commandWord;
    string secondWord;
};

}

#endif /*COMMAND_H_*/
