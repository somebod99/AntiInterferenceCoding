/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *GilberMoorEncode;
    QAction *HammingEncode;
    QAction *GilberMoorDecode;
    QAction *HammingDecode;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *encodeMenu;
    QMenu *decodeMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 706);
        MainWindow->setMinimumSize(QSize(807, 706));
        MainWindow->setMaximumSize(QSize(807, 706));
        GilberMoorEncode = new QAction(MainWindow);
        GilberMoorEncode->setObjectName(QString::fromUtf8("GilberMoorEncode"));
        HammingEncode = new QAction(MainWindow);
        HammingEncode->setObjectName(QString::fromUtf8("HammingEncode"));
        GilberMoorDecode = new QAction(MainWindow);
        GilberMoorDecode->setObjectName(QString::fromUtf8("GilberMoorDecode"));
        HammingDecode = new QAction(MainWindow);
        HammingDecode->setObjectName(QString::fromUtf8("HammingDecode"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 807, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        encodeMenu = new QMenu(menu);
        encodeMenu->setObjectName(QString::fromUtf8("encodeMenu"));
        decodeMenu = new QMenu(menu);
        decodeMenu->setObjectName(QString::fromUtf8("decodeMenu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(encodeMenu->menuAction());
        menu->addAction(decodeMenu->menuAction());
        encodeMenu->addAction(GilberMoorEncode);
        encodeMenu->addAction(HammingEncode);
        decodeMenu->addAction(GilberMoorDecode);
        decodeMenu->addAction(HammingDecode);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Coding", nullptr));
        GilberMoorEncode->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\223\320\270\320\273\321\214\320\261\320\265\321\200\320\260 \320\234\321\203\321\200\320\260", nullptr));
        HammingEncode->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\245\321\215\320\274\320\274\320\270\320\275\320\263\320\260", nullptr));
        GilberMoorDecode->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\223\320\270\320\273\321\214\320\261\320\265\321\200\320\260 \320\234\321\203\321\200\320\260", nullptr));
        HammingDecode->setText(QCoreApplication::translate("MainWindow", " \320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\245\321\215\320\274\320\274\320\270\320\275\320\263\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        encodeMenu->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        decodeMenu->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
