/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *listOfSci;
    QTableWidget *listOfComps;
    QPushButton *linkButton;
    QPushButton *addSciButton;
    QWidget *addSciFrame;
    QLineEdit *inSciName;
    QRadioButton *inSciMale;
    QRadioButton *inSciFemale;
    QDateEdit *inSciBirth;
    QLabel *label;
    QDateEdit *inSciDeath;
    QCheckBox *inSciAlive;
    QLabel *label_2;
    QTextEdit *inSciDesc;
    QPushButton *addSciDone;
    QPushButton *addCompButton;
    QWidget *addCompFrame;
    QLineEdit *inCompName;
    QCheckBox *inCompCreated;
    QSpinBox *inCompYear;
    QComboBox *inCompType;
    QLabel *label_3;
    QTextEdit *inCompDesc;
    QPushButton *addCompDone;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(882, 756);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listOfSci = new QTableWidget(centralWidget);
        listOfSci->setObjectName(QStringLiteral("listOfSci"));
        listOfSci->setGeometry(QRect(10, 10, 331, 421));
        listOfComps = new QTableWidget(centralWidget);
        listOfComps->setObjectName(QStringLiteral("listOfComps"));
        listOfComps->setGeometry(QRect(530, 10, 331, 421));
        linkButton = new QPushButton(centralWidget);
        linkButton->setObjectName(QStringLiteral("linkButton"));
        linkButton->setGeometry(QRect(400, 150, 75, 23));
        addSciButton = new QPushButton(centralWidget);
        addSciButton->setObjectName(QStringLiteral("addSciButton"));
        addSciButton->setGeometry(QRect(20, 450, 75, 23));
        addSciFrame = new QWidget(centralWidget);
        addSciFrame->setObjectName(QStringLiteral("addSciFrame"));
        addSciFrame->setEnabled(true);
        addSciFrame->setGeometry(QRect(10, 470, 321, 221));
        inSciName = new QLineEdit(addSciFrame);
        inSciName->setObjectName(QStringLiteral("inSciName"));
        inSciName->setGeometry(QRect(10, 10, 161, 20));
        inSciName->setMaxLength(32767);
        inSciName->setDragEnabled(false);
        inSciMale = new QRadioButton(addSciFrame);
        inSciMale->setObjectName(QStringLiteral("inSciMale"));
        inSciMale->setGeometry(QRect(10, 40, 82, 17));
        inSciMale->setChecked(true);
        inSciFemale = new QRadioButton(addSciFrame);
        inSciFemale->setObjectName(QStringLiteral("inSciFemale"));
        inSciFemale->setGeometry(QRect(60, 40, 82, 17));
        inSciBirth = new QDateEdit(addSciFrame);
        inSciBirth->setObjectName(QStringLiteral("inSciBirth"));
        inSciBirth->setGeometry(QRect(10, 60, 110, 22));
        inSciBirth->setDate(QDate(1752, 12, 24));
        label = new QLabel(addSciFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 60, 71, 16));
        inSciDeath = new QDateEdit(addSciFrame);
        inSciDeath->setObjectName(QStringLiteral("inSciDeath"));
        inSciDeath->setEnabled(false);
        inSciDeath->setGeometry(QRect(60, 90, 110, 22));
        inSciAlive = new QCheckBox(addSciFrame);
        inSciAlive->setObjectName(QStringLiteral("inSciAlive"));
        inSciAlive->setGeometry(QRect(10, 90, 70, 17));
        inSciAlive->setChecked(true);
        label_2 = new QLabel(addSciFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 90, 71, 16));
        inSciDesc = new QTextEdit(addSciFrame);
        inSciDesc->setObjectName(QStringLiteral("inSciDesc"));
        inSciDesc->setGeometry(QRect(10, 120, 301, 91));
        addSciDone = new QPushButton(addSciFrame);
        addSciDone->setObjectName(QStringLiteral("addSciDone"));
        addSciDone->setGeometry(QRect(210, 10, 75, 23));
        addCompButton = new QPushButton(centralWidget);
        addCompButton->setObjectName(QStringLiteral("addCompButton"));
        addCompButton->setGeometry(QRect(540, 450, 75, 23));
        addCompFrame = new QWidget(centralWidget);
        addCompFrame->setObjectName(QStringLiteral("addCompFrame"));
        addCompFrame->setGeometry(QRect(530, 470, 331, 221));
        inCompName = new QLineEdit(addCompFrame);
        inCompName->setObjectName(QStringLiteral("inCompName"));
        inCompName->setGeometry(QRect(10, 10, 161, 20));
        inCompCreated = new QCheckBox(addCompFrame);
        inCompCreated->setObjectName(QStringLiteral("inCompCreated"));
        inCompCreated->setGeometry(QRect(10, 40, 101, 17));
        inCompYear = new QSpinBox(addCompFrame);
        inCompYear->setObjectName(QStringLiteral("inCompYear"));
        inCompYear->setEnabled(false);
        inCompYear->setGeometry(QRect(10, 60, 91, 22));
        inCompType = new QComboBox(addCompFrame);
        inCompType->setObjectName(QStringLiteral("inCompType"));
        inCompType->setGeometry(QRect(10, 90, 121, 22));
        label_3 = new QLabel(addCompFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 60, 81, 16));
        inCompDesc = new QTextEdit(addCompFrame);
        inCompDesc->setObjectName(QStringLiteral("inCompDesc"));
        inCompDesc->setGeometry(QRect(10, 120, 311, 91));
        addCompDone = new QPushButton(addCompFrame);
        addCompDone->setObjectName(QStringLiteral("addCompDone"));
        addCompDone->setGeometry(QRect(220, 10, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 882, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(inSciBirth);
        label_2->setBuddy(inSciDeath);
        label_3->setBuddy(inCompYear);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);
        QObject::connect(inSciAlive, SIGNAL(toggled(bool)), inSciDeath, SLOT(setDisabled(bool)));
        QObject::connect(addSciButton, SIGNAL(clicked()), addSciFrame, SLOT(show()));
        QObject::connect(addSciDone, SIGNAL(clicked()), addSciFrame, SLOT(hide()));
        QObject::connect(inCompCreated, SIGNAL(toggled(bool)), inCompYear, SLOT(setEnabled(bool)));
        QObject::connect(addCompButton, SIGNAL(clicked()), addCompFrame, SLOT(show()));
        QObject::connect(addCompDone, SIGNAL(clicked()), addCompFrame, SLOT(hide()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        linkButton->setText(QApplication::translate("MainWindow", "Link selected", 0));
        addSciButton->setText(QApplication::translate("MainWindow", "Add scientist", 0));
        inSciName->setInputMask(QString());
        inSciName->setPlaceholderText(QApplication::translate("MainWindow", "Enter name here", 0));
        inSciMale->setText(QApplication::translate("MainWindow", "Male", 0));
        inSciFemale->setText(QApplication::translate("MainWindow", "Female", 0));
        inSciBirth->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd", 0));
        label->setText(QApplication::translate("MainWindow", "Date of birth", 0));
        inSciAlive->setText(QApplication::translate("MainWindow", "Alive", 0));
        label_2->setText(QApplication::translate("MainWindow", "Date of death", 0));
        inSciDesc->setPlaceholderText(QApplication::translate("MainWindow", "Enter a small description", 0));
        addSciDone->setText(QApplication::translate("MainWindow", "Done", 0));
        addCompButton->setText(QApplication::translate("MainWindow", "Add computer", 0));
        inCompName->setPlaceholderText(QApplication::translate("MainWindow", "Enter name here", 0));
        inCompCreated->setText(QApplication::translate("MainWindow", "Was it created?", 0));
        inCompType->clear();
        inCompType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Computer type", 0)
         << QApplication::translate("MainWindow", "Electronical", 0)
         << QApplication::translate("MainWindow", "Transistor", 0)
         << QApplication::translate("MainWindow", "Mechanical", 0)
         << QApplication::translate("MainWindow", "Electromechanical", 0)
        );
        inCompType->setCurrentText(QApplication::translate("MainWindow", "Computer type", 0));
        label_3->setText(QApplication::translate("MainWindow", "Creation year", 0));
        inCompDesc->setPlaceholderText(QApplication::translate("MainWindow", "Enter a small description", 0));
        addCompDone->setText(QApplication::translate("MainWindow", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
