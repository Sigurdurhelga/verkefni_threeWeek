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
    void displayConnections(QString id);

    void fillComboConn();
    void errorHandle(int);
    QString getNumDialog();

private slots:
    // Add buttons
    void on_addSciDone_clicked();
    void on_addCompDone_clicked();

    // Toggle between computers / scientists
    void on_showComps_clicked();
    void on_showSci_clicked();

    // Show more buttons
    void on_showMoreButton_clicked();
    void on_moreDoneButton_clicked();
    void on_moreLinkButton_clicked();

    // Cell editing for lists
    void on_listOfSci_cellChanged(int row, int column);
    void on_listOfSci_cellClicked(int row);
    void on_listOfComps_cellChanged(int row, int column);
    void on_listOfComps_cellClicked(int row);

    // Search functions
    void on_searchText_returnPressed();
    void on_searchButton_clicked();

    void on_removeSelected_clicked();

private:
    Ui::MainWindow *ui;
    QString currSelectedID;
    void config();
    bool canEdit;
    bool whatList;
    int currSelectedRow;
};

#endif // MAINWINDOW_H
