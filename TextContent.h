#ifndef TEXTCONTENT_H
#define TEXTCONTENT_H

#include <string>
using std::string;

// Struct containing different texts that need to be printed out
struct TextContent {
    static string printCurrentRoom(string& description);

    const static string welcome;
    const static string inputError;
    const static string noMoreRooms;
};

/*
namespace GeneralText {
const string welcomeD = "";


}

namespace RoomText {
const string roomA = "";


}*/

#endif // TEXTCONTENT_H
