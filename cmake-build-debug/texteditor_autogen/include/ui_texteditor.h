/********************************************************************************
** Form generated from reading UI file 'texteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_texteditor
{
public:
    QAction *New;
    QAction *Open_file;
    QAction *save;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *texteditor)
    {
        if (texteditor->objectName().isEmpty())
            texteditor->setObjectName(QString::fromUtf8("texteditor"));
        texteditor->resize(800, 600);
        New = new QAction(texteditor);
        New->setObjectName(QString::fromUtf8("New"));
        Open_file = new QAction(texteditor);
        Open_file->setObjectName(QString::fromUtf8("Open_file"));
        save = new QAction(texteditor);
        save->setObjectName(QString::fromUtf8("save"));
        centralwidget = new QWidget(texteditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        texteditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(texteditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        texteditor->setMenuBar(menubar);
        statusbar = new QStatusBar(texteditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        texteditor->setStatusBar(statusbar);

        retranslateUi(texteditor);

        QMetaObject::connectSlotsByName(texteditor);
    } // setupUi

    void retranslateUi(QMainWindow *texteditor)
    {
        texteditor->setWindowTitle(QCoreApplication::translate("texteditor", "texteditor", nullptr));
        New->setText(QCoreApplication::translate("texteditor", "\346\226\260\345\273\272(N)", nullptr));
#if QT_CONFIG(shortcut)
        New->setShortcut(QCoreApplication::translate("texteditor", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        Open_file->setText(QCoreApplication::translate("texteditor", "\346\211\223\345\274\200(O)", nullptr));
#if QT_CONFIG(tooltip)
        Open_file->setToolTip(QCoreApplication::translate("texteditor", "\346\211\223\345\274\200(O)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        Open_file->setShortcut(QCoreApplication::translate("texteditor", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save->setText(QCoreApplication::translate("texteditor", "\344\277\235\345\255\230(s)", nullptr));
#if QT_CONFIG(tooltip)
        save->setToolTip(QCoreApplication::translate("texteditor", "\344\277\235\345\255\230(s)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        save->setShortcut(QCoreApplication::translate("texteditor", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class texteditor: public Ui_texteditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H
