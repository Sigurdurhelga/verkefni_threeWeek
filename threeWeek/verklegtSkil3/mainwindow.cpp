#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"
#include "Scientist.h"
#include "Computers.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addCompFrame->setHidden(1);
    ui->editCompFrame->setHidden(1);
    ui->listOfComps->setHidden(1);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addSciDone_clicked()
{
    bool check = true;
    QMessageBox box;

    if(ui->inSciName->text() == ""){
        box.information(0,"Warning", "Name can't be empty!");
        check = false;
    }
    else if(ui->inSciBirth->date() > ui->inSciDeath->date() && !ui->inSciAlive->isChecked()){
        box.information(0,"Warning", "Death can't have happened before birth");
        check = false;
    }
    else if(ui->inSciDesc->toPlainText() == ""){
        box.information(0,"Warning", "Description can't be empty");
        check = false;
    }
    if(check){

    }
    Controller cont;
    cont.testfunc();
}

void MainWindow::on_removeCompRad_clicked(bool checked)
{

}


