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
    //w.setWindowState(Qt::WindowMaximized);
    //MainWindow* windowPtr = &w;
    w.show();
    w.clearConsole();

    w.addStringToConsole(TextContent::welcome);
    //ZorkUL::updateRoom(ZorkUL::getCurrentRoom(), windowPtr);
    //string roomDescription = ZorkUL::getCurrentRoom()->getShortDescription();
    //w.addStringToConsole(Dialogues::printCurrentRoom(roomDescription));

    int returnCode = a.exec();
    Zork::deleteAll();
    return returnCode;
}