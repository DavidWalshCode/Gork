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
    void inputTextChanged();
    void on_northButton_released();
    void on_southButton_released();
    void on_eastButton_released();
    void on_westButton_released();
    void on_mapButton_released();
    void on_infoButton_released();
    void on_teleportButton_released();
    void on_quitButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
