#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer_ = new QTimer(this);

    connect(timer_, &QTimer::timeout, this, &MainWindow::timer_slot);


}

MainWindow::~MainWindow()
{
    delete ui;

    //print_text();
}


void MainWindow::timer_slot(){


    second++;

    ui->lcdNumberSec->display(second);

    //qDebug() << "timer_slot";


    if(second==60){

        minute++;

        ui->lcdNumberMin->display(minute);

        second=0;

    }




}





void MainWindow::on_stopButton_clicked()
{
    timer_->stop();
}


void MainWindow::on_startButton_clicked()
{
    timer_->start(1000);
}


void MainWindow::on_resetButton_clicked()
{
    //timer->stop();
    second=0;
    minute=0;

    ui->lcdNumberSec->display(second);
    ui->lcdNumberMin->display(minute);
}


void MainWindow::on_pushButton_3_clicked()
{

}

