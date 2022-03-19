#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //push_button2 = new QPushButton(this);
    /*push_button2->setText("Click");
    push_button2->setGeometry(QRect(QPoint(0, 0), QSize(100, 50)));
    connect(push_button2, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked())); */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_northButton_clicked()
{
    ui->textOutput->setText("Go North");
}

void MainWindow::on_eastButton_clicked()
{
    ui->textOutput->setText("Go East");
}

void MainWindow::on_westButton_clicked()
{
    ui->textOutput->setText("Go West");
}

void MainWindow::on_southButton_clicked()
{
    ui->textOutput->setText("Go South");
}

void MainWindow::on_mapButton_clicked()
{
    ui->textOutput->setText("Map");
}

void MainWindow::on_teleportButton_clicked()
{
    ui->textOutput->setText("Teleport");
}

void MainWindow::on_quitButton_clicked()
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

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Forever Sleep", "Are you sure you want to go to sleep Captain?",
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

