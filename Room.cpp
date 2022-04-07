#include "Room.h"
#include "Command.h"

Room::Room(string name)
{
    this->name = name;
}

void Room::setExits(string north, string east, string south, string west)
{
    if (!north.empty())
    {
        exits["north"] = north;
    }
    if (!east.empty())
    {
        exits["east"] = east;
    }
    if (!south.empty())
    {
		exits["south"] = south;
    }
    if (!west.empty())
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
    return "Island = " + name + "\n" + displayItem() + exitString();
}

string Room::exitString()
{
    string exitString = "\nWays to travel =";

    for (auto i = exits.begin(); i != exits.end(); i++)
    {
        // Loop through map
        exitString += "  " + i->first; // Access the "first" element of the pair (direction as a string)
    }

    return exitString;
}

string Room::nextRoom(string direction)
{
    auto next = exits.find(direction); // Returns an iterator for the "pair"

    if (next == exits.end())
    {
        return ""; // If exits.end() was returned, there's no room in that direction.
    }

    return next->second; // If there is a room, return the name
}

void Room::addItem(Item item)
{
    //cout << endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(item);
}

string Room::displayItem()
{
    string tempString = "Items around = ";
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
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
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
        return false;
    }

    else if (itemsInRoom.size() > 0)
    {
        int x = (0);
        for (int n = sizeItems; n > 0; n--)
        {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
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
