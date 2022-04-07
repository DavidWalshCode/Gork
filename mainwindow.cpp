#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Zork.h"
#include "TextContent.h"

#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QScrollBar>

using namespace zork;

//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->inputConsole->setFocus();
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearConsole()
{
    ui->outputConsole->clear();
}

// Printing to console
void MainWindow::addStringToConsole(const string &input)
{
    ui->outputConsole->setText(QString::fromStdString("\n") + QString::fromStdString(input));
}

// Printing to console
void MainWindow::addQStringToConsole(const QString &input)
{
    ui->outputConsole->setText(QString::fromStdString("\n") + input);
}

// Clears the console and prints
void MainWindow::overwriteConsole(const string &input)
{
    ui->outputConsole->clear();
    addStringToConsole(input);
}

// Handling what happens when the "enter" key is pressed on the text edit input.
void MainWindow::inputTextChanged()
{
    // Converting from QString to string and finding the index of "enter" or "\n"
    string input = ui->inputConsole->toPlainText().toStdString();
    size_t newlineIndex = input.find('\n');

    // Preventing users from entering several enter lines
    if (newlineIndex == 0)
    {
        ui->inputConsole->clear();
        return;
    }

    // Removing the newline from the input to be later passed into parseInput
    input = input.substr(0, newlineIndex);

    // Checks if there are any newlines or if the "enter" key is pressed
    if (newlineIndex != string::npos && input.size() > 0)
    {
        this->parseInput(input);
        this->ui->inputConsole->clear();
    }
}

// Trying to convert input to a command and printing out the appropriate output.
void MainWindow::parseInput(const string &input)
{
    Parser& parser = *Zork::getParser();

    Command* command = parser(input);

    string inputString = "> " + input + "\n\n";

    string output = Zork::processCommand(*command);

    // Processes errors
    if (output.compare("") == 0)
    {
        overwriteConsole(inputString + TextContent::inputError);
        return;
    }

    overwriteConsole(inputString + output);

    delete command;

    ui->inputConsole->setFocus();
}

/*
 * Buttons
 */
void MainWindow::on_northButton_released()
{
    parseInput("go north");
}

void MainWindow::on_eastButton_released()
{
    parseInput("go east");
}

void MainWindow::on_southButton_released()
{
    parseInput("go south");
}

void MainWindow::on_westButton_released()
{
    parseInput("go west");
}

void MainWindow::on_mapButton_released()
{
    parseInput("map");
}

void MainWindow::on_infoButton_released()
{
    parseInput("info");
}

void MainWindow::on_teleportButton_released()
{
    parseInput("teleport");
}

void MainWindow::on_quitButton_released()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "Forever Sleep", "Are you sure you want to go to sleep Captain?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        parseInput("quit");
    }
    else
    {
       //qDebug() << "No is clicked";
    }
}

