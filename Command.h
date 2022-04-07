#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
using namespace std;

class Command
{
public:
    Command(string firstWord, string secondWord);
    string getCommandWord();
    string getSecondWord();
    bool isUnknown();
    bool hasSecondWord();

private:
	string commandWord;
	string secondWord;
};

#endif /*COMMAND_H_*/
