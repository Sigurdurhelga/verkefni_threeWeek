#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayAllScientists();
    void displayAllComputers();
    void errorHandle(int);

private slots:
    void on_addSciDone_clicked();

    void on_addCompDone_clicked();

    void on_showComps_clicked();

    void on_showSci_clicked();


    void on_listOfSci_cellChanged(int row, int column);

    void on_listOfComps_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
    void config();
    bool canEdit;
};

#endif // MAINWINDOW_H
