#include "textcontent.h"

const string TextContent::welcome = "This is Wordleville, a harsh world"
                                      " where your status and prestige is determined by your Wordle skills."
                                      " Your father throws you off the train. \"If you can't"
                                      " earn at least $1000 tonight, don't even think about coming back to me.\""
                                      " You set off on your way...\n"
                                      "If you seek assistance, enter the 'info' command.\n";

string TextContent::printCurrentRoom(string& description){
    return "You are currently in: " + description + ". What is your next move?\n";
}
