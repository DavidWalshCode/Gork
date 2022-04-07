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
	void setExits(string north, string east, string south, string west);
	string shortDescription();
	string longDescription();
	string nextRoom(string direction);
	void addItem(Item item);
	string displayItem();
	int isItemInRoom(string inString);
	void removeItemFromRoom(int location);

private:
	string name;
	map<string, string> exits;
	string exitString();
	vector <Item> itemsInRoom;
};

#endif
