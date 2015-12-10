#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addSciFrame->setHidden(1);
    ui->addCompFrame->setHidden(1);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addSciDone_clicked()
{

}
