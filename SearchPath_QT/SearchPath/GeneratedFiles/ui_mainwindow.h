/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionResetDes;
    QAction *actionResetStart;
    QAction *actionAddObstacle;
    QAction *actionRemoveObs;
    QAction *actionSearchOrder;
    QAction *actionPathLength;
    QAction *actionClearPath;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionScaling;
    QAction *actionAddStart;
    QAction *actionDisplaySearchTree;
    QAction *actionDisplayPathLength;
    QAction *actionStart_Search;
    QAction *actionAstar;
    QAction *actionDJ;
    QAction *actionShowAllPath;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuDisplay;
    QMenu *menuHelp;
    QMenu *menuMethod;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(665, 491);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/self-driving cute.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        actionNew = new QAction(MainWindowClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionQuit = new QAction(MainWindowClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionResetDes = new QAction(MainWindowClass);
        actionResetDes->setObjectName(QStringLiteral("actionResetDes"));
        actionResetDes->setCheckable(true);
        actionResetStart = new QAction(MainWindowClass);
        actionResetStart->setObjectName(QStringLiteral("actionResetStart"));
        actionResetStart->setCheckable(true);
        actionAddObstacle = new QAction(MainWindowClass);
        actionAddObstacle->setObjectName(QStringLiteral("actionAddObstacle"));
        actionAddObstacle->setCheckable(true);
        actionRemoveObs = new QAction(MainWindowClass);
        actionRemoveObs->setObjectName(QStringLiteral("actionRemoveObs"));
        actionRemoveObs->setCheckable(true);
        actionSearchOrder = new QAction(MainWindowClass);
        actionSearchOrder->setObjectName(QStringLiteral("actionSearchOrder"));
        actionSearchOrder->setCheckable(true);
        actionPathLength = new QAction(MainWindowClass);
        actionPathLength->setObjectName(QStringLiteral("actionPathLength"));
        actionPathLength->setCheckable(true);
        actionClearPath = new QAction(MainWindowClass);
        actionClearPath->setObjectName(QStringLiteral("actionClearPath"));
        actionClearPath->setCheckable(false);
        actionClearPath->setEnabled(true);
        actionZoom_In = new QAction(MainWindowClass);
        actionZoom_In->setObjectName(QStringLiteral("actionZoom_In"));
        actionZoom_Out = new QAction(MainWindowClass);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        actionScaling = new QAction(MainWindowClass);
        actionScaling->setObjectName(QStringLiteral("actionScaling"));
        actionAddStart = new QAction(MainWindowClass);
        actionAddStart->setObjectName(QStringLiteral("actionAddStart"));
        actionDisplaySearchTree = new QAction(MainWindowClass);
        actionDisplaySearchTree->setObjectName(QStringLiteral("actionDisplaySearchTree"));
        actionDisplayPathLength = new QAction(MainWindowClass);
        actionDisplayPathLength->setObjectName(QStringLiteral("actionDisplayPathLength"));
        actionStart_Search = new QAction(MainWindowClass);
        actionStart_Search->setObjectName(QStringLiteral("actionStart_Search"));
        actionAstar = new QAction(MainWindowClass);
        actionAstar->setObjectName(QStringLiteral("actionAstar"));
        actionAstar->setCheckable(true);
        actionDJ = new QAction(MainWindowClass);
        actionDJ->setObjectName(QStringLiteral("actionDJ"));
        actionDJ->setCheckable(true);
        actionShowAllPath = new QAction(MainWindowClass);
        actionShowAllPath->setObjectName(QStringLiteral("actionShowAllPath"));
        actionShowAllPath->setCheckable(true);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 665, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuDisplay = new QMenu(menuBar);
        menuDisplay->setObjectName(QStringLiteral("menuDisplay"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuMethod = new QMenu(menuBar);
        menuMethod->setObjectName(QStringLiteral("menuMethod"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setMovable(true);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        mainToolBar->setFloatable(true);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuDisplay->menuAction());
        menuBar->addAction(menuMethod->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionResetDes);
        menuEdit->addAction(actionResetStart);
        menuEdit->addAction(actionAddObstacle);
        menuEdit->addAction(actionRemoveObs);
        menuEdit->addSeparator();
        menuEdit->addAction(actionStart_Search);
        menuDisplay->addAction(actionSearchOrder);
        menuDisplay->addAction(actionPathLength);
        menuDisplay->addAction(actionClearPath);
        menuDisplay->addSeparator();
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionShowAllPath);
        menuMethod->addAction(actionAstar);
        menuMethod->addAction(actionDJ);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionStart_Search);
        mainToolBar->addSeparator();

        retranslateUi(MainWindowClass);
        QObject::connect(actionStart_Search, SIGNAL(triggered()), MainWindowClass, SLOT(on_btnStart_clicked()));
        QObject::connect(actionShowAllPath, SIGNAL(toggled(bool)), MainWindowClass, SLOT(on_chkShowAllPath_toggled(bool)));
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindowClass, SLOT(on_actionQuit_triggered()));
        QObject::connect(actionResetDes, SIGNAL(toggled(bool)), MainWindowClass, SLOT(on_actionResetDestination_triggered(bool)));
        QObject::connect(actionResetStart, SIGNAL(toggled(bool)), MainWindowClass, SLOT(on_actionResetStart_triggered(bool)));
        QObject::connect(actionAddObstacle, SIGNAL(toggled(bool)), MainWindowClass, SLOT(on_actionAddObs_triggered(bool)));
        QObject::connect(actionRemoveObs, SIGNAL(toggled(bool)), MainWindowClass, SLOT(on_actionDelObs_triggered(bool)));
        QObject::connect(actionDisplayPathLength, SIGNAL(toggled(bool)), MainWindowClass, SLOT(on_actionShowSearchedPathTreeWithDistances_triggered(bool)));
        QObject::connect(actionDisplaySearchTree, SIGNAL(toggled(bool)), MainWindowClass, SLOT(on_actionShowSearchedPathTree_triggered(bool)));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindowClass", "New", 0));
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindowClass", "Save", 0));
        actionQuit->setText(QApplication::translate("MainWindowClass", "Quit", 0));
        actionResetDes->setText(QApplication::translate("MainWindowClass", "ResetDes", 0));
        actionResetStart->setText(QApplication::translate("MainWindowClass", "ResetStart", 0));
        actionAddObstacle->setText(QApplication::translate("MainWindowClass", "AddObs", 0));
        actionRemoveObs->setText(QApplication::translate("MainWindowClass", "RemoveObs", 0));
        actionSearchOrder->setText(QApplication::translate("MainWindowClass", "SearchOrder", 0));
        actionPathLength->setText(QApplication::translate("MainWindowClass", "PathLength", 0));
        actionClearPath->setText(QApplication::translate("MainWindowClass", "ClearPath", 0));
        actionZoom_In->setText(QApplication::translate("MainWindowClass", "Zoom In", 0));
        actionZoom_Out->setText(QApplication::translate("MainWindowClass", "Zoom Out", 0));
        actionScaling->setText(QApplication::translate("MainWindowClass", "Scaling", 0));
        actionAddStart->setText(QApplication::translate("MainWindowClass", "AddObs", 0));
        actionDisplaySearchTree->setText(QApplication::translate("MainWindowClass", "DisplaySearchTree", 0));
        actionDisplayPathLength->setText(QApplication::translate("MainWindowClass", "DisplayPathLength", 0));
        actionStart_Search->setText(QApplication::translate("MainWindowClass", "Start Search", 0));
        actionAstar->setText(QApplication::translate("MainWindowClass", "Astar", 0));
        actionDJ->setText(QApplication::translate("MainWindowClass", "Dj", 0));
        actionShowAllPath->setText(QApplication::translate("MainWindowClass", "ShowAllPath", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindowClass", "Edit", 0));
        menuDisplay->setTitle(QApplication::translate("MainWindowClass", "Display", 0));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "Help", 0));
        menuMethod->setTitle(QApplication::translate("MainWindowClass", "Method", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
