#ifndef TEXTCONTENT_H
#define TEXTCONTENT_H

#include <string>
using std::string;

namespace zork
{

// Struct containing different texts that need to be printed out
struct TextContent {
    static string printCurrentRoom(string& description);

    const static string welcome;
    const static string inputError;
    const static string noMoreRooms;
    const static string onGo;
    const static string onTeleport;
    const static string showMap;
};

}

#endif // TEXTCONTENT_H
