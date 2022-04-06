#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clearConsole();
    void addStringToConsole(string input);
    void addQStringToConsole(QString input);
    void overwriteConsole(string input);
    void updateBackground(string path);
    void parseInput(string input);
    void scrollToBottom();

private slots:
    void on_northButton_pressed();
    void on_eastButton_pressed();
    void on_southButton_pressed();
    void on_westButton_pressed();
    void on_mapButton_pressed();
    void on_infoButton_pressed();
    void on_teleportButton_pressed();
    void on_quitButton_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
