/********************************************************************************
** Form generated from reading UI file 'qtpaint.ui'
**
** Created: Fri Jan 18 22:31:13 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPAINT_H
#define UI_QTPAINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTPAINTClass
{
public:
    QWidget *widget;
    QFrame *frame;

    void setupUi(QWidget *QTPAINTClass)
    {
        if (QTPAINTClass->objectName().isEmpty())
            QTPAINTClass->setObjectName(QString::fromUtf8("QTPAINTClass"));
        QTPAINTClass->resize(600, 400);
        widget = new QWidget(QTPAINTClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 30, 341, 321));
        frame = new QFrame(QTPAINTClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 120, 120, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(QTPAINTClass);

        QMetaObject::connectSlotsByName(QTPAINTClass);
    } // setupUi

    void retranslateUi(QWidget *QTPAINTClass)
    {
        QTPAINTClass->setWindowTitle(QApplication::translate("QTPAINTClass", "QTPAINT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QTPAINTClass: public Ui_QTPAINTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPAINT_H
