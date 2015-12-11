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
    displayAllScientists();

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
    cont.getScientists();
}

void MainWindow::on_removeCompRad_clicked(bool checked)
{

}

void MainWindow::displayAllScientists()
{
    Controller cont;
    QVector<Scientist> scientists = cont.getScientists();
    ui->listOfSci->clearContents();

    ui->listOfSci->setRowCount(scientists.size());

    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists.at(row);

        QString id = currentScientist.returnID();
        QString gender = currentScientist.returnSex();
        QString name = currentScientist.returnName();
        QString dateBirth = currentScientist.dateofBirth();
        QString dateDeath = currentScientist.dateofDeath();
        QString description = currentScientist.returnDescription();

        ui->listOfSci->setItem(row, 0, new QTableWidgetItem(id));
        ui->listOfSci->setItem(row, 1, new QTableWidgetItem(name));
        ui->listOfSci->setItem(row, 2, new QTableWidgetItem(gender));
        ui->listOfSci->setItem(row, 3, new QTableWidgetItem(dateBirth));
        ui->listOfSci->setItem(row, 4, new QTableWidgetItem(dateDeath));
        ui->listOfSci->setItem(row, 5, new QTableWidgetItem(description));
    }

    return;
}


void MainWindow::displayAllComputers()
{
    Controller cont;
    QVector<Computers> computers = cont.getComputers();
    ui->listOfComps->clearContents();
    ui->listOfComps->setRowCount(computers.size());

    for (unsigned int row = 0; row < computers.size(); row++)
    {
        Computers currentComputer = computers.at(row);

        QString id = currentComputer.returnID();
        QString name = currentComputer.returnName();
        QString created = currentComputer.returnCreated();
        QString creationDate = currentComputer.returnCreationYear();
        QString description = currentComputer.returnDescription();

        ui->listOfComps->setItem(row, 0, new QTableWidgetItem(id));
        ui->listOfComps->setItem(row, 1, new QTableWidgetItem(name));
        ui->listOfComps->setItem(row, 2, new QTableWidgetItem(created));
        ui->listOfComps->setItem(row, 3, new QTableWidgetItem(creationDate));
        ui->listOfComps->setItem(row, 4, new QTableWidgetItem(description));
    }

    return;
}

void MainWindow::on_showComps_clicked()
{
    displayAllComputers();
}

void MainWindow::on_showSci_clicked()
{
    displayAllScientists();
}
