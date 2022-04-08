#include "Room.h"
#include "Command.h"

using namespace zork;

Room::Room(string name)
{
    this->name = name;
}

void Room::setExits(Room* north, Room* east, Room* south, Room* west)
{
    if (north != NULL)
    {
        exits["north"] = north;
    }
    if (east != NULL)
    {
        exits["east"] = east;
    }
    if (south != NULL)
    {
        exits["south"] = south;
    }
    if (west != NULL)
    {
        exits["west"] = west;
    }
}

string Room::shortDescription()
{
    return name;
}

string Room::longDescription()
{
    return "Island: " + name + "\n" + displayItem() + exitString();
}

string Room::exitString()
{
    string exitString = "\nWays to travel, Captain:";

    for (auto i = exits.begin(); i != exits.end(); i++)
    {
        // Loop through map
        exitString += "  " + i->first; // Access the first element of the pair (direction as a string)
    }

    return exitString;
}

Room* Room::nextRoom(string direction)
{
    map<string, Room*>::iterator next = exits.find(direction); // Returns an iterator for the pair

    if (next == exits.end()){
        return NULL; // If exits.end() was returned, there are no room in that direction.
    }

    // If there is a room, remove the "second" (Room*) part of the pair (<string, Room*>) and return it
    return next->second;
}

void Room::addItem(Item item)
{
    itemsInRoom.push_back(item);
}

string Room::displayItem()
{
    string tempString = "Items around: ";
    int sizeItems = (itemsInRoom.size());

    if (itemsInRoom.size() < 1)
    {
        tempString = "No items around";
    }
    else if (itemsInRoom.size() > 0)
    {
        int x = (0);
        for (int n = sizeItems; n > 0; n--)
        {
            tempString = tempString + itemsInRoom[x].getName() + "  " ;
            x++;
        }
    }

    return tempString;
}

int Room::numberOfItems()
{
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());

    if (itemsInRoom.size() < 1)
    {
        return -1;
    }

    else if (itemsInRoom.size() > 0)
    {
        int x = (0);
        for (int n = sizeItems; n > 0; n--)
        {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getName());
            if (tempFlag == 0)
            {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }

            x++;
        }
    }

    return -1;
}
