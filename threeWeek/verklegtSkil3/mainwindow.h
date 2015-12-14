#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Scientist.h>
#include <Computers.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayAllScientists(QVector<Scientist>);
    void displayAllComputers(QVector<Computers>);
    void errorHandle(int);
    QString getNumDialog();

private slots:
    void on_addSciDone_clicked();
    void on_addCompDone_clicked();

    void on_showComps_clicked();
    void on_showSci_clicked();

    void on_listOfSci_cellChanged(int row, int column);
    void on_listOfSci_cellClicked(int row);
    void on_listOfComps_cellChanged(int row, int column);
    void on_listOfComps_cellClicked(int row);

    void on_removeSelected_clicked();
    void on_searchButton_clicked();
    void on_searchText_returnPressed();

    void on_showMoreButton_clicked();

private:
    Ui::MainWindow *ui;
    QString currSelectedID;
    void config();
    bool canEdit;
    bool whatList;
    int currSelectedRow;
};

#endif // MAINWINDOW_H
