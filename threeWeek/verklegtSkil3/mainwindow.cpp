#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"
#include "Scientist.h"
#include "Computers.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addCompFrame->setHidden(1);
    ui->editCompFrame->setHidden(1);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addSciDone_clicked()
{

}

void MainWindow::on_removeCompRad_clicked(bool checked)
{

}

