#ifndef TEXTCONTENT_H
#define TEXTCONTENT_H

#include <string>
using std::string;

// Struct containing different texts that need to be printed out
struct Dialogues {
    static string printCurrentRoom(string& description);

    const static string welcome;
};

#endif // TEXTCONTENT_H
