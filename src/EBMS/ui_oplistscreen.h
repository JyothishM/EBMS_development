/********************************************************************************
** Form generated from reading UI file 'oplistscreen.ui'
**
** Created: Fri Dec 28 15:28:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPLISTSCREEN_H
#define UI_OPLISTSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpListScreen
{
public:

    void setupUi(QWidget *OpListScreen)
    {
        if (OpListScreen->objectName().isEmpty())
            OpListScreen->setObjectName(QString::fromUtf8("OpListScreen"));
        OpListScreen->resize(400, 300);

        retranslateUi(OpListScreen);

        QMetaObject::connectSlotsByName(OpListScreen);
    } // setupUi

    void retranslateUi(QWidget *OpListScreen)
    {
        OpListScreen->setWindowTitle(QApplication::translate("OpListScreen", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpListScreen: public Ui_OpListScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPLISTSCREEN_H
