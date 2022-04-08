#include "TextContent.h"

using namespace zork;

const string TextContent::welcome = "Welcome to the land of the living Captain. "
                                    "I can feel the eyes of the depths watching us, we better go now.\n";

const string TextContent::inputError = "What did you say Captain? The crew didn't hear you.\n";

const string TextContent::noMoreRooms = "No more areas to pillage this way. We must try another direction Captain.\n";

const string TextContent::onGo = "Set sail you dirty bigle rats! Much love to you all hahaha.\n";

const string TextContent::onTeleport = "Get the ship's mage! You are chaos incarnate, green mystical light soars through you and visions of endless possibilites appear. "
                                       "You do not get the time to choose however.\n";

const string TextContent::showMap = "Captain here be the rum soaked map! Who forget to mark the names of the islands?\n"
                                    "[h] --- [f] --- [g]\n"
                                    "           |         \n"
                                    "           |         \n"
                                    "[c] --- [a] --- [b]\n"
                                    "           |         \n"
                                    "           |         \n"
                                    "[i] --- [d] --- [e]\n"
                                    "           |         \n"
                                    "           |         \n"
                                    "          [j]        \n";

string TextContent::printCurrentRoom(string& description)
{
    return "We are currently in " + description + ", Captain. What is our next move?\n";
}
