#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

class ZorkUL
{

public:
    ZorkUL();
    void play();
    void go(string direction);

private:
	Parser parser;
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

#endif /*ZORKUL_H_*/
