#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"
#include "Scientist.h"
#include "Computers.h"
#include "ComboBoxItemDelegate.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <QTableWidget>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config();
    on_showSci_clicked();
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
    QVector<Scientist> list;
    QString name;
    QString gender = "Male";
    QString birth;
    QString death = "Alive";
    QString desc;

    if(ui->inSciName->text() == ""){
        errorHandle(0);
        check = false;
    }
    else if(ui->inSciBirth->date() > ui->inSciDeath->date() && !ui->inSciAlive->isChecked()){
        errorHandle(2);
        check = false;
    }
    else if(ui->inSciDesc->toPlainText() == ""){
        errorHandle(1);
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
        list = cont.getScientists("");
        displayAllScientists(list);
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
    QVector<Computers> list;
    QString name;
    QString created = "No";
    QString creationYear = "Never";
    QString type;
    QString description;


    if(ui->inCompName->text() == ""){
        check = false;
        errorHandle(0);
    }
    else if(ui->inCompYear->text() == ""){
        check = false;
        errorHandle(4);
    }
    else if(ui->inCompType->text() == ""){
        check = false;
        errorHandle(3);
    }
    else if(ui->inCompDesc->toPlainText() == ""){
        check = false;
        errorHandle(1);
    }
    if(check){
        name = ui->inCompName->text();
        if(ui->inCompCreated->isChecked()){
            created = "Yes";
            creationYear = ui->inCompYear->text();
        }
        type = ui->inCompType->text();
        description = ui->inCompDesc->toPlainText();
        cont.add(name, created, creationYear, type, description, false);
        list = cont.getComputers("");
        displayAllComputers(list);
        ui->inCompDesc->clear();
        ui->inCompName->clear();
        ui->inCompCreated->setChecked(false);
    }
}

void MainWindow::displayAllScientists(QVector<Scientist> scientists)
{
    canEdit = false;
    ui->listOfSci->clearContents();
    ui->listOfSci->setRowCount(scientists.size());

    for (int row = 0; row < scientists.size(); row++)
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


void MainWindow::displayAllComputers(QVector<Computers> computers)
{
    canEdit = false;
    ui->listOfComps->clearContents();
    ui->listOfComps->setRowCount(computers.size());

    for (int row = 0; row < computers.size(); row++)
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
    ui->listOfComps->setHidden(1);
    ui->listOfSci->setColumnHidden(0, true);
    ui->listOfComps->setColumnHidden(0,true);
    ui->listOfSci->setColumnWidth(1, 140);
    ui->listOfSci->setColumnWidth(2, 70);
    ui->listOfSci->setColumnWidth(3, 115);
    ui->listOfSci->setColumnWidth(4, 115);
    ui->listOfSci->setColumnWidth(5, 532);
    ui->listOfComps->setColumnWidth(1,140);
    ui->listOfComps->setColumnWidth(2,70);
    ui->listOfComps->setColumnWidth(3, 110);
    ui->listOfComps->setColumnWidth(4, 95);
    ui->listOfComps->setColumnWidth(5,557);
    ComboBoxItemDelegate* sexDelegate = new ComboBoxItemDelegate(ui->listOfSci);
    sexDelegate->setColumnIndex(2);
    sexDelegate->addOption("Male");
    sexDelegate->addOption("Female");
    ui->listOfSci->setItemDelegate(sexDelegate);
    ComboBoxItemDelegate* createdDelegate = new ComboBoxItemDelegate(ui->listOfComps);
    createdDelegate->setColumnIndex(2);
    createdDelegate->addOption("Yes");
    createdDelegate->addOption("No");
    ui->listOfComps->setItemDelegate(createdDelegate);
}

void MainWindow::errorHandle(int i){
    QMessageBox box;
    QString title = "Error";
    QString content;

    switch (i) {
    case 0:
        content = "Invalid name";
        break;
    case 1:
        content = "Invalid description";
        break;
    case 2:
        content = "Birth can't happen before death";
        break;
    case 3:
        content = "Invalid type selected";
        break;
    case 4:
        content = "Invalid creation year. Must be a number or \"Never\"";
        break;
    case 5:
        content = "Invalid date";
        break;
    case 6:
        content = "Invalid death date must be a date \"yyyy-MM-dd\" or \"Alive\"";
        break;

    default:
        break;
    }
    box.warning(QApplication::activeWindow(), title, content);
}

QString MainWindow::getNumDialog(){
    QRegExp isDigit("^[0-9]+$");
    bool ok;
    QString num = QInputDialog::getText(QApplication::activeWindow(), "Creation year", "Enter creation year", QLineEdit::Normal, QDir::home().dirName(), &ok);
    if(isDigit.exactMatch(num) && ok){
        return num;
    }
    else{
        return "";
    }
}

void MainWindow::on_showComps_clicked()
{
    whatList = false;
    Controller cont;
    QVector<Computers> list;
    list = cont.getComputers("");
    displayAllComputers(list);
}

void MainWindow::on_showSci_clicked()
{
    whatList = true;
    Controller cont;
    QVector<Scientist> list;
    list = cont.getScientists("");
    displayAllScientists(list);
}

void MainWindow::on_listOfSci_cellChanged(int row, int column)
{
    Controller cont;
    if(canEdit){
        bool check = true;
        bool alive = false;
        QString death = ui->listOfSci->item(row,4)->text();
        QDate currB = QDate::fromString(ui->listOfSci->item(row, 3)->text(), "yyyy-MM-dd");
        QDate currD = QDate::fromString(death, "yyyy-MM-dd");
        if(death == "Alive"){
            alive = true;
        }
        if(column == 1 && ui->listOfSci->item(row, column)->text() == ""){
            errorHandle(0);
            check = false;
        }
        else if(column == 4 && !currD.isValid() && death != "Alive"){
            errorHandle(6);
            check = false;
        }
        else if(((column == 3 && (currB > currD)) || (column == 4 && (currB > currD))) && (currB.isValid() && currD.isValid()) && !alive){
            errorHandle(2);
            check = false;
        }
        else if(((!currB.isValid() || !currD.isValid()) && !alive) || (death != "Alive" && !currD.isValid()) || (!currB.isValid() && alive)){
            errorHandle(5);
            check = false;
        }
        else if(column == 5 && ui->listOfSci->item(row, column)->text() == ""){
            errorHandle(1);
            check = false;
        }
        if(check){
            QString id = ui->listOfSci->item(row, 0)->text();
            QString newThing = ui->listOfSci->item(row, column)->text();
            cont.edit(id, newThing, column, true);
        }
    }
}



void MainWindow::on_listOfComps_cellChanged(int row, int column)
{
    Controller cont;
    if(canEdit){
        QRegExp isDigit("^[0-9]+$");
        bool check = true;
        QString createdS = ui->listOfComps->item(row, 2)->text();
        QString newThing = ui->listOfComps->item(row, column)->text();
        if(column == 1 && ui->listOfComps->item(row, column)->text() == ""){
            errorHandle(0);
            check = false;
        }
        else if(column == 3 && !isDigit.exactMatch(newThing) && newThing != "Never"){
            errorHandle(4);
            check = false;
        }
        else if(column == 4 && ui->listOfComps->item(row, column)->text() == ""){
            errorHandle(3);
            check = false;
        }
        else if(column == 5 && ui->listOfComps->item(row, column)->text() == ""){
            errorHandle(1);
            check = false;
        }
        if(check){

            QString id = ui->listOfComps->item(row, 0)->text();

            if(column == 2 && createdS == "No"){
                ui->listOfComps->item(row, 3)->setText("Never");
                cont.edit(id, "Never", 3, false);
            }
            else if(column == 2 && createdS == "Yes"){
                QString newnum;
                if(!isDigit.exactMatch(ui->listOfComps->item(row,3)->text()))
                    newnum = getNumDialog();
                    if(newnum != ""){
                        ui->listOfComps->item(row, 3)->setText(newnum);
                        cont.edit(id, newnum, 3, false);
                    }
            }
            else if(column == 3 && isDigit.exactMatch(newThing)){
                ui->listOfComps->item(row, 2)->setText("Yes");
                cont.edit(id, "Yes", column, false);
            }
            else if(column == 3 && newThing == "Never"){
                ui->listOfComps->item(row, 2)->setText("No");
                cont.edit(id, "No", 2, false);
            }

            cont.edit(id, newThing, column, false);
        }
    }
}

void MainWindow::on_removeSelected_clicked()
{
    Controller cont;
    if(whatList){
        cont.remove(currSelectedID, whatList);
        ui->listOfSci->removeRow(currSelectedRow);
    }
    else{
        cont.remove(currSelectedID, whatList);
        ui->listOfComps->removeRow(currSelectedRow);
    }
    currSelectedRow = -1;
    currSelectedID = -1;
}

void MainWindow::on_listOfComps_cellClicked(int row, int column)
{
    currSelectedID = ui->listOfComps->item(row, 0)->text();
    currSelectedRow = row;
}

void MainWindow::on_listOfSci_cellClicked(int row, int column)
{
    currSelectedID = ui->listOfSci->item(row, 0)->text();
    currSelectedRow = row;
}

void MainWindow::on_searchButton_clicked()
{
    Controller cont;
    QString name = ui->searchText->text();
    if(whatList){
        QVector<Scientist> list;
        list = cont.getScientists(name);
        displayAllScientists(list);
    }
    else{
        QVector<Computers> list;
        list = cont.getComputers(name);
        displayAllComputers(list);
    }
}
