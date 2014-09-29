/********************************************************************************
** Form generated from reading UI file 'collidingmice.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLIDINGMICE_H
#define UI_COLLIDINGMICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_collidingmiceClass
{
public:

    void setupUi(QWidget *collidingmiceClass)
    {
        if (collidingmiceClass->objectName().isEmpty())
            collidingmiceClass->setObjectName(QStringLiteral("collidingmiceClass"));
        collidingmiceClass->resize(600, 400);

        retranslateUi(collidingmiceClass);

        QMetaObject::connectSlotsByName(collidingmiceClass);
    } // setupUi

    void retranslateUi(QWidget *collidingmiceClass)
    {
        collidingmiceClass->setWindowTitle(QApplication::translate("collidingmiceClass", "collidingmice", 0));
    } // retranslateUi

};

namespace Ui {
    class collidingmiceClass: public Ui_collidingmiceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLIDINGMICE_H
