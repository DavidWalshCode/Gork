#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <QApplication>
#include <QTextStream>
#include <QDebug>

#include "mainwindow.h"
#include "TextContent.h"
#include "Zork.h"

using namespace zork;

map<string, Room*> Zork::rooms;
Room* Zork::currentRoom;
Parser* Zork::parser;

void Zork::createRooms()
{
    // Creating rooms
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("Seacove Ruins");
    b = new Room("Land of the Free");
    c = new Room("Kraken Island");
    d = new Room("Seaweed Retreat");
    e = new Room("Bloodmoon Bay");
    f = new Room("Freebooter Anchorage");
    g = new Room("Reef of Old Salt");
    h = new Room("Cavern of Storms");
    i = new Room("Isle of the Sunken");
    j = new Room("Rumrunner Redland");

    // Creating items
    Item lamp("Lamp", 2, 11);
    Item rum("Bottle of Rum", 3, 33);
    Item pistol("Flicklock Pistol", 2, 22);
    Item cutlass("Cutlass", 4, 44);

    // Adding items to rooms
    b->addItem(lamp);
    d->addItem(rum);
    f->addItem(pistol);
    j->addItem(cutlass);

    // Setting exits
    //         (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, j, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(d, NULL, NULL, NULL);

    rooms.emplace("Seacove Ruins", a);
    rooms.emplace("Land of the Free", b);
    rooms.emplace("Kraken Island", c);
    rooms.emplace("Seaweed Retreat", d);
    rooms.emplace("Bloodmoon Bay", e);
    rooms.emplace("Freebooter Anchorage", f);
    rooms.emplace("Reef of Old Salt", g);
    rooms.emplace("Cavern of Storms", h);
    rooms.emplace("Isle of the Sunken", i);
    rooms.emplace("Rumrunner Redland", j);

    // Start off in this room
    setCurrentRoom(a);
}

// Memory management
void Zork::deleteAll()
{
    // pair<const string, Room*>&
    for (auto& p : rooms)
    {
        delete p.second;
    }

    delete parser;
}

/*
 * Given a command, process (that is: execute) the command.
 */
string Zork::processCommand(Command& command)
{
    string output = "";

    if (command.isUnknown())
    {
        output += TextContent::inputError;
        return output;
    }

    string commandWord = command.getCommandWord();

    if (commandWord.compare("info") == 0)
    {
        output += showHelp();
    }
    else if (commandWord.compare("map") == 0)
    {
        output += TextContent::showMap;
    }
    else if (commandWord.compare("go") == 0)
    {
        // If the go command works, execute it
        if (go(command) == true)
        {
            output += TextContent::onGo;
            output += currentRoom->longDescription();
        }
        else
        {
            output += TextContent::inputError;
        }

    }
    else if (commandWord.compare("teleport") == 0)
    {
        teleportRandomRoom();
        output += TextContent::onTeleport;
        output += currentRoom->longDescription();
    }
    /*
    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord())
        {
            output += TextContent::inputError;
        }
        else if (command.hasSecondWord())
        {
            cout << "You're trying to take " << command.getSecondWord() << endl;
            int location = currentRoom->isItemInRoom(command.getSecondWord());

            if (location < 0)
            {
                cout << "Item is not in room..." << endl;
            }
            else
            {
                cout << "Item is in room!" << endl;
                cout << "Index number " << location << endl;
                cout << endl;
                cout << currentRoom->longDescription() << endl;
            }
        }
    }
    */
    else if (commandWord.compare("quit") == 0)
    {
        if (command.hasSecondWord())
        {
            output += TextContent::inputError;
        }
        else
        {
            Zork::deleteAll();
        }

        exit(0); // signal to quit
    }

    return output;
}

/*
 * Returns all commands as a string
 */
string Zork::showHelp()
{
    string output = "Captain here are the commands you can shout to the crew:\n";
    output += Zork::parser->showCommandsAsString();
    return output;
}

bool Zork::go(Command command)
{
    if (!command.hasSecondWord())
    {
        return false;
    }

    string direction = command.getSecondWord();
    go(direction);

    return true;
}

void Zork::go(string direction)
{
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
        return;
    }
    else
    {
        setCurrentRoom(nextRoom);
    }
}

void Zork::teleportRandomRoom()
{
    auto it = rooms.begin();
    advance(it, rand() % rooms.size());

    setCurrentRoom(it->second);
}

void Zork::setCurrentRoom(Room* name)
{
    currentRoom = name;
}

Room* Zork::getCurrentRoom()
{
    return currentRoom;
}

void Zork::setParser(Parser *parser){
    Zork::parser = parser;
}

Parser* Zork::getParser(){
    return Zork::parser;
}
