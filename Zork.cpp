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

using namespace std;

Parser *Zork::parser;

int main(int argc, char* argv[])
{
    Parser* parser = new Parser();
    Zork::setParser(parser);

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    MainWindow *windowPtr = &w;
    w.show();
    w.clearConsole();

    w.addStringToConsole(TextContent::welcome);
    //ZorkUL::updateRoom(ZorkUL::getCurrentRoom(), windowPtr);
    //string roomDescription = ZorkUL::getCurrentRoom()->getShortDescription();
    //w.addStringToConsole(Dialogues::printCurrentRoom(roomDescription));

    delete Zork::getParser();
    return a.exec();
}

Zork::Zork()
{
	createRooms();
}

void Zork::createRooms()
{
    // Creating rooms
    Room a("a");
    a.addItem(Item("x", 1, 11));
    a.addItem(Item("y", 2, 22));

    Room b("b");
    b.addItem(Item("xx", 3, 33));
    b.addItem(Item("yy", 4, 44));

    Room c("c"),
         d("d"),
         e("e"),
         f("f"),
         g("g"),
         h("h"),
         i("i"),
         j("j");

    // Setting exits
    //         (N,   E,   S,   W)
    a.setExits("f", "b", "d", "c");
    b.setExits("", "", "", "a");
    c.setExits("", "a", "", "");
    d.setExits("a", "e", "j", "i");
    e.setExits("", "", "", "d");
    f.setExits("", "g", "a", "h");
    g.setExits("", "", "", "f");
    h.setExits("", "f", "", "");
    i.setExits("", "d", "", "");
    j.setExits("d", "", "", "");

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
    setCurrentRoom("a");
}

/**
 * Given a command, process (that is: execute) the command.
 */
string Zork::processCommand(Command& command, MainWindow* window)
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
        output += printHelp();
    }
    else if (commandWord.compare("map") == 0)
    {
        output += "[h] --- [f] --- [g]"
                  "         |         "
                  "         |         "
                  "[c] --- [a] --- [b]"
                  "         |         "
                  "         |         "
                  "[i] --- [d] --- [e]"
                  "         |         "
                  "         |         "
                  "        [j]        ";
    }
    else if (commandWord.compare("go") == 0)
    {
        cout << "You begin walking" << endl;
        go(command);

        if (go(command))
        {
            Zork::updateRoom(currentRoom, window);
            output += currentRoom->longDescription();
        }
        else
        {
            output += TextContent::inputError;
        }

    }
    else if (commandWord.compare("teleport") == 0)
    {
        cout << "Green mystical light soars through you and visions of endless possibilites appear" << endl;
        teleportRoom(command);
    }
    else if (commandWord.compare("random") == 0)
    {
        cout << "You are chaos incarnate" << endl;
        teleportRandomRoom();
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
    }
    else if (commandWord.compare("quit") == 0)
    {
        if (command.hasSecondWord())
        {
            cout << "Overdefined input"<< endl;
        }
        else
        {
            // Make delete command and put here, something like (Zork::deleteAllStuff();)
        }

        exit(0); // signal to quit
	}

    return output;
}

/** COMMANDS **/
string Zork::printHelp()
{
    string output = "Captain here are the commands you can shout to the crew: ";
    output += Zork::parser->showAllCommands();
    return output;
}

void Zork::go(Command command)
{
    if (!command.hasSecondWord())
    {
        cout << "Incomplete input" << endl;
        return;
    }

    string direction = command.getSecondWord();

    go(direction);
}

void Zork::teleportRandomRoom()
{
    auto it = rooms.begin();
    advance(it, rand() % rooms.size());

    setCurrentRoom(it->first);

    cout << currentRoom->longDescription() << endl;
}

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
}

void Zork::go(string direction)
{
    // Make the direction lowercase
    // transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    // Move to the next room
    string nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom.empty())
    {
        cout << "You can't move in that direction" << endl;
    }
    else
    {
        setCurrentRoom(nextRoom);
        cout << currentRoom->longDescription() << endl;
    }
}

void Zork::setCurrentRoom(string name)
{
    auto it = rooms.find(name);

    if (it != rooms.end())
    {
        currentRoom = &it->second;
    }
}

void Zork::setParser(Parser *parser){
    Zork::parser = parser;
}

Parser* Zork::getParser(){
    return Zork::parser;
}
