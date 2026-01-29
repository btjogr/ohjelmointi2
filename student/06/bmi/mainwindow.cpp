#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{

}




void MainWindow::on_countButton_clicked()
{

    QString weight_= ui->weightLineEdit->text();
    QString height_= ui->heightLineEdit->text();



    if(weight_ == " " || height_ == " " || height_.toInt()==0){
       ui->resultLabel->setText( "Cannot count");
        ui->infoTextBrowser->clear();
    }

    else{

        float ans =  (weight_.toFloat() / (height_.toFloat() * height_.toFloat()))*10000;
        ui->resultLabel->setText(QString::number(ans));

        if(ans<18.5 ){
            ui->infoTextBrowser->setText("Underweight");
        }
        else if (ans>25) {
            ui->infoTextBrowser->setText("Overweight");
        }
        else {
            ui->infoTextBrowser->setText("Normal range");
        }

    }




}




