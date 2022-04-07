#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;
using std::vector;

class Room
{
public:
	Room(string name);
	int numberOfItems();
    void setExits(Room* north, Room* east, Room* south, Room* west);
	string shortDescription();
	string longDescription();
    Room* nextRoom(string direction);
	void addItem(Item item);
	string displayItem();
	int isItemInRoom(string inString);
	void removeItemFromRoom(int location);

private:
	string name;
    map<string, Room*> exits;
	string exitString();
	vector <Item> itemsInRoom;
};

#endif
