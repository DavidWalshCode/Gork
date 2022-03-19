#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    void on_eastButton_clicked();

    void on_northButton_clicked();

    void on_westButton_clicked();

    void on_southButton_clicked();

    void on_quitButton_clicked();

    void on_mapButton_clicked();

    void on_teleportButton_clicked();

private:
    Ui::MainWindow *ui;
    //QPushButton *push_button2;
};
#endif // MAINWINDOW_H
