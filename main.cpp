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

int main(int argc, char* argv[])
{
    Parser* parser = new Parser();
    Zork::setParser(parser);

    Zork::createRooms();

    QApplication a(argc, argv);
    MainWindow w;

    w.resize(1300, 690);
    w.show();
    w.clearConsole();

    string roomDescription = Zork::getCurrentRoom()->shortDescription();
    w.addStringToConsole(TextContent::welcome + TextContent::printCurrentRoom(roomDescription));

    int returnCode = a.exec();
    Zork::deleteAll();
    return returnCode;
}
