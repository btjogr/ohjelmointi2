#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "chess.hh"
#include <iostream>

Chess peli;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    //peli.start_game(WHITE);
    //peli.print_board();


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{



}

