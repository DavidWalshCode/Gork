#include "Parser.h"

Parser::Parser() {
	commands = new CommandWords();
}

Command* Parser::getCommand()
{
	string inputLine = ""; // Will hold the full input line
	string word1;
	string word2;
	string buffer;
	vector<string> words;

	cout << "> "; // Print prompt

	getline(cin, buffer, '\n');	// read a line from cin to "buffer"

	string::size_type pos = 0, last_pos = 0;

	// Break "buffer" up by spaces
	bool finished = false;
	while (!finished)
	{
		pos = buffer.find_first_of(' ', last_pos);	// Find and remember first space.
		if (pos == string::npos ) // If we found the last word,
		{
			words.push_back(buffer.substr(last_pos));	// Add it to vector "words"
			finished = true;				// And finish searching.
		}
		else
		{					// Otherwise add to vector and move on to next word.
			words.push_back(buffer.substr(last_pos, pos - last_pos));
			last_pos = pos + 1;
		}
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

	// Note: We just ignore the rest of the input line.
	// Now check whether this word is known. If so, create a command with it.
	// If not, create a "nil" command (empty string for unknown command).

	if (commands->isCommand(word1))
	{
		return new Command(word1, word2);
	}
	else
	{
		return new Command("", word2);
	}
}

/**
 * Print out a list of valid command words.
 */
void Parser::showCommands()
{
	commands->showAll();
}
