#include "TextContent.h"

const string TextContent::welcome = "Welcome to the land of the living Captain."
                                      "I can feel the eyes watching us, we better go.\n";

const string TextContent::inputError = "What did you say Captain? The crew didn't hear you.\n";

const string TextContent::noMoreRooms = "No more areas this way. We must try another direction Captain.\n";

string TextContent::printCurrentRoom(string& description)
{
    return "We are currently in: " + description + " Captain. What is our next move?\n";
}
