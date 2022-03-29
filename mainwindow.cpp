#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Zork.h"
#include "TextContent.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearConsole(){
    ui->outputConsole->clear();
}

// Scrolls to the bottom of the output
void MainWindow::scrollToBottom(){
    //ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
}

// Printing to game console - Supports string and QString
void MainWindow::addStringToConsole(string input){
    //qDebug("Hello");
    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + QString::fromStdString(input));
    scrollToBottom();
}

void MainWindow::addQStringToConsole(QString input){
    //qDebug("Hello");
    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + input);
    scrollToBottom();
}

// Clears the console and prints something
void MainWindow::overwriteConsole(string input){
    ui->outputConsole->clear();
    addStringToConsole(input);

    scrollToBottom();
}

// Trying to convert input to a command and printing out the appropriate output.
void MainWindow::parseInput(string input){
    Command *command = Zork::getParser()->convertToCommand(input);
    //    addStringToConsole("> " + input + "\n");
    overwriteConsole("> " + input + "\n");
    string output = Zork::processCommand(*command, this);

    // Processes errors
    if(output.compare("") == 0){
        //addStringToConsole(Dialogues::inputError);
        overwriteConsole(TextContent::inputError);
        return;
    }

    //addStringToConsole(output);
    overwriteConsole(output);
    //ui->moneyLabel->setText(QString::fromStdString("Money: " + std::to_string(Zork::getMoney())));

    delete command;

    ui->input->setFocus();
    scrollToBottom();
}


// Buttons
void MainWindow::on_northButton_pressed()
{
    parseInput("go north");
}

void MainWindow::on_eastButton_pressed()
{
    parseInput("go east");
}

void MainWindow::on_southButton_pressed()
{
    parseInput("go south");
}

void MainWindow::on_westButton_pressed()
{
    parseInput("go west");
}

void MainWindow::on_mapButton_pressed()
{
    parseInput("map");
}

void MainWindow::on_interactButton_pressed()
{
    parseInput("take");
}

void MainWindow::on_teleportButton_pressed()
{
    parseInput("random");
}

void MainWindow::on_quitButton_pressed()
{
    // Notes about Message Boxes
    /*
        void about
        void aboutQt
        StandardButton critical
        StandardButton information
        StandardButton question
        StandardButton warning
        e.g. QMessageBox::question(this, "My Title", "This is my custom message");
    */

    QMessageBox::StandardButton reply = QMessageBox::warning(this, "Forever Sleep", "Are you sure you want to go to sleep Captain?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
       qDebug() << "No is clicked";
    }
}

