#include "TextContent.h"

const string TextContent::welcome = "Welcome to the land of the living Captain."
                                      "I can feel the eyes watching us, we better go.\n";

const string TextContent::inputError = "Invalid command, please try again.\n";

const string TextContent::noMoreRooms = "No more areas this way. Try another direction.\n";

string TextContent::printCurrentRoom(string& description)
{
    return "We are currently in: " + description + " Captain. What is our next move?\n";
}
