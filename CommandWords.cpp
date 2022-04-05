#include "CommandWords.h"

vector<string> CommandWords::validCommands;

/**
 * Constructor - initialise the command words.
 */
CommandWords::CommandWords() {
	// Populate the vector if we haven't already.
    if (validCommands.empty())
    {
		validCommands.push_back("go");
        validCommands.push_back("map");
        validCommands.push_back("teleport");
        validCommands.push_back("random");
		validCommands.push_back("take");
        validCommands.push_back("info");
        validCommands.push_back("quit");
	}
}

/**
 * Check whether a given String is a valid command word.
 * Return true if it is, false if it isn't.
 **/
bool CommandWords::isCommand(string aString)
{
	for (unsigned int i = 0; i < validCommands.size(); i++)
	{
		if (validCommands[i].compare(aString) == 0)
        {
			return true;
        }
	}
    // If we get here, the string was not found in the commands
	return false;
}

/*
 * Print all valid commands to System.out.
 */
string CommandWords::showAllCommands()
{
    string allValidCommands = "";

    //Loops through validCommands and prints each to the screen.
    for (unsigned int i = 0; i < validCommands.size() - 1; i++)
    {
        allValidCommands += validCommands.at(i) + ", ";
    }

    // Last command won't have any commas
    allValidCommands += validCommands.at(validCommands.size() - 1);

    return allValidCommands;
}
