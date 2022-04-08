#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "Item.h"

using std::string;
using std::map;
using std::vector;

namespace zork
{

class Room
{
public:
	Room(string name);

	int numberOfItems();
	string shortDescription();
	string longDescription();
	string displayItem();

    void setExits(Room* north, Room* east, Room* south, Room* west);
    Room* nextRoom(string direction);
    void addItem(Item item);
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);

private:
	string name;
    map<string, Room*> exits;
	string exitString();
	vector <Item> itemsInRoom;
};

}

#endif
