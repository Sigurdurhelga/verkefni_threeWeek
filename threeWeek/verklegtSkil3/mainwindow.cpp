#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"
#include "Scientist.h"
#include "Computers.h"
#include "comboBoxItemDelegate.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config();

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addSciDone_clicked()
{
    Controller cont;
    bool check = true;
    QMessageBox box;
    QString name;
    QString gender = "Male";
    QString birth;
    QString death = "Alive";
    QString desc;

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
        name = ui->inSciName->text();
        if(ui->inSciFemale->isChecked()){
            gender = "Female";
        }
        birth = ui->inSciBirth->date().toString("yyyy-MM-dd");
        if(!ui->inSciAlive->isChecked()){
            death = ui->inSciDeath->date().toString("yyyy-MM-dd");
        }
        desc = ui->inSciDesc->toPlainText();

        cont.add(name, gender, birth, death, desc, true);
        displayAllScientists();
        ui->inSciName->clear();
        ui->inSciAlive->setChecked(true);
        ui->inSciDesc->clear();

    }
}

void MainWindow::on_addCompDone_clicked()
{
    Controller cont;
    bool check = true;
    QMessageBox warning;
    QString name;
    QString created = "No";
    QString creationYear = "Never";
    QString type;
    QString description;


    if(ui->inCompName->text() == ""){
        check = false;
        warning.information(0, "Warning", "Computer name can't be empty");
    }
    else if(ui->inCompYear->text() == ""){
        check = false;
        warning.information(0, "Warning", "Creation year invalid");
    }
    else if(ui->inCompType->currentText() == "Computer type"){
        check = false;
        warning.information(0, "Warning", "Computer type invalid");
    }
    else if(ui->inCompDesc->toPlainText() == ""){
        check = false;
        warning.information(0, "Warning", "Description can't be empty");
    }
    if(check){
        name = ui->inCompName->text();
        if(ui->inCompCreated->isChecked()){
            created = "Yes";
            creationYear = ui->inCompYear->text();
        }
        type = ui->inCompType->currentText();
        description = ui->inCompDesc->toPlainText();
        cont.add(name, created, creationYear, type, description, false);
        displayAllComputers();
        ui->inCompDesc->clear();
        ui->inCompName->clear();
        ui->inCompCreated->setChecked(false);
    }
}

void MainWindow::displayAllScientists()
{
    canEdit = false;
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
    canEdit = true;
    return;
}


void MainWindow::displayAllComputers()
{
    canEdit = false;
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
        QString type = currentComputer.returnType();
        QString description = currentComputer.returnDescription();


        ui->listOfComps->setItem(row, 0, new QTableWidgetItem(id));
        ui->listOfComps->setItem(row, 1, new QTableWidgetItem(name));
        ui->listOfComps->setItem(row, 2, new QTableWidgetItem(created));
        ui->listOfComps->setItem(row, 3, new QTableWidgetItem(creationDate));
        ui->listOfComps->setItem(row, 4, new QTableWidgetItem(type));
        ui->listOfComps->setItem(row, 5, new QTableWidgetItem(description));
    }
    canEdit = true;
    return;
}

void MainWindow::config(){
    ui->addCompFrame->setHidden(1);
    ui->editCompFrame->setHidden(1);
    ui->listOfComps->setHidden(1);
    ui->listOfSci->setColumnHidden(0, true);
    ui->listOfComps->setColumnHidden(0,true);
    ui->listOfSci->setColumnWidth(1, 120);
    ui->listOfSci->setColumnWidth(2, 70);
    ui->listOfSci->setColumnWidth(3, 100);
    ui->listOfSci->setColumnWidth(4, 100);
    ui->listOfSci->setColumnWidth(5, 410);
    ui->listOfComps->setColumnWidth(1,120);
    ui->listOfComps->setColumnWidth(2,60);
    ui->listOfComps->setColumnWidth(3, 100);
    ui->listOfComps->setColumnWidth(4, 85);
    ui->listOfComps->setColumnWidth(5,440);
    ComboBoxItemDelegate* sexDelegate = new ComboBoxItemDelegate(ui->listOfSci);
    sexDelegate->setColumnIndex(2);
    sexDelegate->addOption("Male");
    sexDelegate->addOption("Female");
    ui->listOfSci->setItemDelegate(sexDelegate);
    ComboBoxItemDelegate* typeDelegate = new ComboBoxItemDelegate(ui->listOfComps);
    typeDelegate->setColumnIndex(4);
    typeDelegate->addOption("Electronical");
    typeDelegate->addOption("Transistor");
    typeDelegate->addOption("Mechanical");
    typeDelegate->addOption("Electromechanical");
    ui->listOfComps->setItemDelegate(typeDelegate);


}


void MainWindow::on_showComps_clicked()
{
    displayAllComputers();
}

void MainWindow::on_showSci_clicked()
{
    displayAllScientists();
}

void MainWindow::on_listOfSci_cellChanged(int row, int column)
{
    Controller cont;
    if(canEdit){
        QString id = ui->listOfSci->item(row, 0)->text();
        QString newThing = ui->listOfSci->item(row, column)->text();
        cont.edit(id, newThing, column, true);
    }
}



void MainWindow::on_listOfComps_cellChanged(int row, int column)
{
    Controller cont;
    if(canEdit){
        QString id = ui->listOfComps->item(row, 0)->text();
        QString newThing = ui->listOfComps->item(row, column)->text();
        cont.edit(id, newThing, column, false);
    }
}
