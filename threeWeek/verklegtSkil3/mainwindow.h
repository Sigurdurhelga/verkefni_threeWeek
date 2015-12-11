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

private slots:
    void on_addSciDone_clicked();

    void on_removeCompRad_clicked(bool checked);


    void on_listOfSci_clicked(const QModelIndex &index);

    void on_showComps_clicked();

    void on_showSci_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
