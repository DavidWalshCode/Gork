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
    void addStringToConsole(const string &input);
    void addQStringToConsole(const QString &input);
    void overwriteConsole(const string &input);
    void parseInput(const string &input);

private slots:
    void northButtonPressed();
    void eastButtonPressed();
    void southButtonPressed();
    void westButtonPressed();
    void mapButtonPressed();
    void infoButtonPressed();
    void teleportButtonPressed();
    void quitButtonPressed();
    void inputTextChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
