#ifndef ZORK_H_
#define ZORK_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Zork
{

public:
    Zork();
    void play();
    void go(string direction);

    static void setParser(Parser *parser);
    static Parser* getParser();

private:
    static Parser* parser;
	Room *currentRoom;
    map<string, Room> rooms;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
    void go(Command command);
    void teleportRandomRoom();
    void teleportRoom(Command command);
    void createItems();
    void displayItems();
    void setCurrentRoom(string name);
};

#endif /*ZORK_H_*/
