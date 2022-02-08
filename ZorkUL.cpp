#include <iostream>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char** argv)
{
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL()
{
	createRooms();
}

void ZorkUL::createRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a");
    a->addItem(new Item("x", 1, 11));
    a->addItem(new Item("y", 2, 22));
    b = new Room("b");
    b->addItem(new Item("xx", 3, 33));
    b->addItem(new Item("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");

//             (N, E, S, W)
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

    currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play()
{
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and execute them until the ZorkUL game is over.

    bool finished = false;

    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        // with ("return new Command(...)")
        delete command;
    }

    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome()
{
    cout << "The start of a grand adventure..."<< endl;
    cout << "Type info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command)
{
    if (command.isUnknown())
    {
        cout << "Invalid input" << endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

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
        goRoom(command);
    }

    else if (commandWord.compare("teleport") == 0)
    {
        cout << "Green mystical light soars through you and visions of endless possibilites appear" << endl;
        teleportRoom(command);
    }

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord())
        {
            cout << "Incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord())
            {
                cout << "You're trying to take " + command.getSecondWord() << endl;
                int location = currentRoom->isItemInRoom(command.getSecondWord());
                if (location  < 0 )
                    cout << "Item is not in room..." << endl;
                else
                    cout << "Item is in room!" << endl;
                    cout << "Index number " << + location << endl;
                    cout << endl;
                    cout << currentRoom->longDescription() << endl;
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
            cout << "Overdefined input"<< endl;
        else
            return true; // signal to quit
	}

	return false;
}

/** COMMANDS **/
void ZorkUL::printHelp()
{
    cout << "Valid inputs are: " << endl;
    parser.showCommands();
}

void ZorkUL::goRoom(Command command)
{
    if (!command.hasSecondWord())
    {
        cout << "Incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "Underdefined input"<< endl;
    else
    {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
	}
}

void ZorkUL::teleportRoom(Command command)
{
    if (!command.hasSecondWord())
    {
        cout << "Incomplete input" << endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    currentRoom = nextRoom;
    cout << currentRoom->longDescription() << endl;
}

string ZorkUL::go(string direction)
{
    // Make the direction lowercase
    // transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    // Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        return("Direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

string ZorkUL::teleport(string room)
{
    // Make the direction lowercase
    // transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    // Move to the next room
    Room* nextRoom = currentRoom->nextRoom(room);
    if (nextRoom == NULL)
        return("Direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
