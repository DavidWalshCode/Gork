#ifndef ZORK_H_
#define ZORK_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Item.h"
#include "mainwindow.h"
#include <iostream>
#include <string>
#include <map>

// Namespace, all Zork game logic should live inside the zork namespace
namespace zork
{

class Zork
{
public:
    static void go(string direction);
    static bool go(Command command);

    static void setParser(Parser *parser);
    static Parser* getParser();

    static void createRooms();
    static string processCommand(Command& command);

    static void deleteAll();

private:
    static Room* currentRoom;
    static map<string, Room*> rooms;

    static string showHelp();

    static Parser* parser;
    static void setCurrentRoom(Room* name);

    static void teleportRandomRoom();
    static void teleportRoom(Command command);

    static void createItems();
    static void displayItems();
};

}

#endif /*ZORK_H_*/
