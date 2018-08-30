/********************************************************************************
** Form generated from reading UI file 'realsense.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALSENSE_H
#define UI_REALSENSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Realsense
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuExit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Realsense)
    {
        if (Realsense->objectName().isEmpty())
            Realsense->setObjectName(QStringLiteral("Realsense"));
        Realsense->resize(400, 300);
        actionExit = new QAction(Realsense);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(Realsense);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 50, 80, 20));
        Realsense->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Realsense);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        Realsense->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Realsense);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Realsense->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Realsense);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Realsense->setStatusBar(statusBar);

        menuBar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Realsense);

        QMetaObject::connectSlotsByName(Realsense);
    } // setupUi

    void retranslateUi(QMainWindow *Realsense)
    {
        Realsense->setWindowTitle(QApplication::translate("Realsense", "Realsense", nullptr));
        actionExit->setText(QApplication::translate("Realsense", "Exit", nullptr));
        pushButton->setText(QApplication::translate("Realsense", "Start", nullptr));
        menuExit->setTitle(QApplication::translate("Realsense", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Realsense: public Ui_Realsense {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALSENSE_H
