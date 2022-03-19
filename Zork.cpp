#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <QApplication>

#include "Zork.h"
#include "mainwindow.h"
#include "TextContent.h"

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

    delete Zork::getParser();
    return a.exec();
}

Zork::Zork()
{
	createRooms();
}

void Zork::createRooms()
{
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

//             (N,   E,   S,   W)
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

    setCurrentRoom("a");
}

/**
 *  Main play routine.  Loops until end of play.
 */
void Zork::play()
{
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and execute them until the ZorkUL game is over.

    bool finished = false;

    while (!finished)
    {
        // Create pointer to command and give it a command.
        Command* command = parser->getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        // with ("return new Command(...)")
        delete command;
    }

    cout << endl;
    cout << "End" << endl;
}

void Zork::printWelcome()
{
    cout << "The start of a grand adventure..."<< endl;
    cout << "Type info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is returned.
 */
bool Zork::processCommand(Command command)
{
    if (command.isUnknown())
    {
        cout << "Invalid input" << endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
    {
        printHelp();
    }
    else if (commandWord.compare("map") == 0)
    {
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "        [j]        " << endl;
    }
    else if (commandWord.compare("go") == 0)
    {
        cout << "You begin walking" << endl;
        go(command);
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
    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0)
    {
        if (command.hasSecondWord())
        {
            cout << "Overdefined input"<< endl;
        }
        else
        {
            return true; // signal to quit
        }
	}

	return false;
}

/** COMMANDS **/
void Zork::printHelp()
{
    cout << "Valid inputs are: " << endl;
    parser->showCommands();
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
