#include "Parser.h"

using namespace zork;

// Constructor
Parser::Parser()
{
	commands = new CommandWords();
}

// Destructor
Parser::~Parser()
{
    delete commands;
}

Command* Parser::commandConverter(string input)
{
    string word1, word2;
	vector<string> words;

	string::size_type pos = 0, last_pos = 0;

    pos = input.find_first_of(' ', last_pos); // Find and remember first space

    // npos tells you if there is no string found.
    if (pos == string::npos )
    {
        words.push_back(input); // Get the first and only word
    }
    else
    {
        words.push_back(input.substr(0, pos));
        words.push_back(input.substr(pos + 1, input.size() - pos - 1));
    }

    if (words.size() == 1) // Was only 1 word entered?
    {
        word1 = words[0]; // Get first word
    }
    else if (words.size() >= 2) // Were at least 2 words entered?
    {
        word1 = words[0]; // Get first word
        word2 = words[1]; // Get second word
    }

    return new Command(word1, word2);
}

string Parser::showCommandsAsString()
{
    return commands->showAllCommands();
}
