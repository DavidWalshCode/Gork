#include "TextContent.h"

using namespace zork;

const string TextContent::welcome = "Welcome to the land of the living Captain. "
                                      "I can feel the eyes of the depths watching us, we better go now.\n";

const string TextContent::inputError = "What did you say Captain? The crew didn't hear you.\n";

const string TextContent::noMoreRooms = "No more areas this way. We must try another direction Captain.\n";

const string TextContent::onTeleport = "Get the ship's mage! You are chaos incarnate, green mystical light soars through you and visions of endless possibilites appear. "
                                       "You do not get time to chosoe however.\n";

string TextContent::printCurrentRoom(string& description)
{
    return "We are currently in " + description + ", Captain. What is our next move?\n";
}
