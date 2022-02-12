#ifndef COMMANDWORDS_H_
#define COMMANDWORDS_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CommandWords
{

public:
    CommandWords();
    bool isCommand(string aString);
    void showAll();

private:
	//Define a static vector for our valid command words.
	//We'll populate this in the class constructor
	static vector<string> validCommands;
};


#endif /*COMMANDWORDS_H_*/
