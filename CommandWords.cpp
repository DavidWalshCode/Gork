#include "CommandWords.h"

using namespace zork;

vector<string> CommandWords::validCommands;

/*
 * Constructor - initialise the command words.
 */
CommandWords::CommandWords()
{
	// Populate the vector if we haven't already.
    if (validCommands.empty())
    {
		validCommands.push_back("go");
        validCommands.push_back("map");
        validCommands.push_back("teleport");
		validCommands.push_back("take");
        validCommands.push_back("info");
        validCommands.push_back("quit");
	}
}

/*
 * Check whether a given String is a valid command word.
 * Return true if it is, false if it isn't.
 */
bool CommandWords::isCommand(string myCommand)
{
	for (unsigned int i = 0; i < validCommands.size(); i++)
	{
        if (validCommands[i].compare(myCommand) == 0)
        {
            // myCommand is a command
			return true;
        }
	}

    // myCommand is not a command
	return false;
}

/*
 * Inserts all valid commands into a String
 */
string CommandWords::showAllCommands()
{
    string allValidCommands = "";

    // Loops through validCommands and prints each to the screen.
    for (unsigned int i = 0; i < validCommands.size() - 1; i++)
    {
        allValidCommands += validCommands.at(i) + ", ";
    }

    // Last command won't have any commas
    allValidCommands += validCommands.at(validCommands.size() - 1);

    return allValidCommands;
}
