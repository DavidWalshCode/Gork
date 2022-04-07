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

    a = new Room("a");
    b = new Room("b");
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");

    // Creating items
    Item x("x", 2, 11);
    Item y("y", 2, 22);
    Item xx("xx", 3, 33);
    Item yy("yy", 4, 44);

    // Adding items to rooms
    a->addItem(x);
    a->addItem(y);
    b->addItem(xx);
    b->addItem(yy);

    // Setting exits
    //         (N,   E,   S,   W)
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

    rooms.emplace("a", a);
    rooms.emplace("b", b);
    rooms.emplace("c", c);
    rooms.emplace("d", d);
    rooms.emplace("e", e);
    rooms.emplace("f", f);
    rooms.emplace("g", g);
    rooms.emplace("h", h);
    rooms.emplace("i", i);
    rooms.emplace("j", j);

    // Start off in this room
    setCurrentRoom(a);
}

// Memory management
void Zork::deleteAll()
{
    //pair<const string, Room*>&
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
            //go(command);
            output += currentRoom->longDescription();
        }
        else
        {
            output += TextContent::inputError;
        }

    }
    else if (commandWord.compare("random") == 0)
    {
        teleportRandomRoom();
        output += TextContent::onTeleport;
        output += currentRoom->longDescription();
    }
    /*
    else if (commandWord.compare("teleport") == 0)
    {
        //cout << "Green mystical light soars through you and visions of endless possibilites appear" << endl;
        teleportRoom(command);
    }
    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord())
        {
            cout << "Incomplete input"<< endl;
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
    } */
    else if (commandWord.compare("quit") == 0)
    {
        if (command.hasSecondWord())
        {
            output += TextContent::inputError;
        }
        else
        {
            // Make delete command and put here, something like (Zork::deleteAllStuff();)
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
    // Make the direction lowercase
    // transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    // Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
        return;
        //cout << "You can't move in that direction" << endl;
    }
    else
    {
        setCurrentRoom(nextRoom);
        //cout << currentRoom->longDescription() << endl;
    }
}

void Zork::teleportRandomRoom()
{
    auto it = rooms.begin();
    advance(it, rand() % rooms.size());

    // Need to update teleport func because of room change
    //setCurrentRoom(it->first);
}

/*
void Zork::teleportRoom(Command command)
{
    if (!command.hasSecondWord())
    {
        cout << "Incomplete input" << endl;
        return;
    }

    string destination = command.getSecondWord();
    setCurrentRoom(destination);

    cout << currentRoom->longDescription() << endl;
}*/

void Zork::setCurrentRoom(Room* name)
{
    //    auto it = rooms.find(name);

    //    if (it != rooms.end())
    //    {
    //        currentRoom = &it->second;
    //    }
    currentRoom = name;
}

void Zork::setParser(Parser *parser){
    Zork::parser = parser;
}

Parser* Zork::getParser(){
    return Zork::parser;
}
