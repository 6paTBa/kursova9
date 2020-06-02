/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *num_of_cities;
    QLabel *label;
    QLineEdit *diff_way_finish;
    QLabel *label_3;
    QLineEdit *diff_way_start;
    QPushButton *diff_ways_bttn;
    QLineEdit *longest_way_start;
    QLineEdit *longest_way_finish;
    QPushButton *longest_way_bttn;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *shortest_way_bttn;
    QLineEdit *shortest_way_finish;
    QLineEdit *shortest_way_start;
    QLabel *label_8;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QLabel *label_2;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(823, 466);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        num_of_cities = new QLineEdit(centralWidget);
        num_of_cities->setObjectName(QString::fromUtf8("num_of_cities"));
        num_of_cities->setGeometry(QRect(180, 10, 41, 31));
        QFont font;
        font.setPointSize(10);
        num_of_cities->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 161, 31));
        diff_way_finish = new QLineEdit(centralWidget);
        diff_way_finish->setObjectName(QString::fromUtf8("diff_way_finish"));
        diff_way_finish->setGeometry(QRect(390, 300, 91, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 310, 251, 20));
        diff_way_start = new QLineEdit(centralWidget);
        diff_way_start->setObjectName(QString::fromUtf8("diff_way_start"));
        diff_way_start->setGeometry(QRect(270, 300, 91, 31));
        diff_ways_bttn = new QPushButton(centralWidget);
        diff_ways_bttn->setObjectName(QString::fromUtf8("diff_ways_bttn"));
        diff_ways_bttn->setGeometry(QRect(500, 300, 89, 25));
        longest_way_start = new QLineEdit(centralWidget);
        longest_way_start->setObjectName(QString::fromUtf8("longest_way_start"));
        longest_way_start->setGeometry(QRect(180, 370, 91, 31));
        longest_way_finish = new QLineEdit(centralWidget);
        longest_way_finish->setObjectName(QString::fromUtf8("longest_way_finish"));
        longest_way_finish->setGeometry(QRect(300, 370, 91, 31));
        longest_way_bttn = new QPushButton(centralWidget);
        longest_way_bttn->setObjectName(QString::fromUtf8("longest_way_bttn"));
        longest_way_bttn->setGeometry(QRect(410, 370, 89, 25));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 380, 181, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 380, 21, 17));
        QFont font1;
        font1.setPointSize(13);
        label_5->setFont(font1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 250, 21, 17));
        label_6->setFont(font1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 250, 181, 17));
        shortest_way_bttn = new QPushButton(centralWidget);
        shortest_way_bttn->setObjectName(QString::fromUtf8("shortest_way_bttn"));
        shortest_way_bttn->setGeometry(QRect(410, 240, 89, 25));
        shortest_way_finish = new QLineEdit(centralWidget);
        shortest_way_finish->setObjectName(QString::fromUtf8("shortest_way_finish"));
        shortest_way_finish->setGeometry(QRect(300, 240, 91, 31));
        shortest_way_start = new QLineEdit(centralWidget);
        shortest_way_start->setObjectName(QString::fromUtf8("shortest_way_start"));
        shortest_way_start->setGeometry(QRect(180, 240, 91, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(370, 310, 21, 17));
        label_8->setFont(font1);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(520, 230, 61, 41));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(610, 290, 61, 41));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(510, 360, 61, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 231, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(490, 60, 291, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 823, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\320\276\321\200\320\276\320\264\320\276\320\262:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\260\320\267\320\275\321\213\321\205 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\320\276\320\262 \320\270\320\267", nullptr));
        diff_ways_bttn->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        longest_way_bttn->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\275\320\265\320\271\321\210\320\270\320\271 \320\277\321\203\321\202\321\214 \320\270\320\267", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\262", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\262", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\270\320\271 \320\277\321\203\321\202\321\214 \320\270\320\267", nullptr));
        shortest_way_bttn->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\262", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \320\264\320\273\321\217 \320\274\320\260\321\202\321\200\320\270\321\206\321\213 \321\201\320\274\320\265\320\266\320\275\320\276\321\201\321\202\320\270:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \320\264\320\273\321\217 \320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\262\321\213\320\262\320\276\320\264\320\260 \320\263\321\200\320\260\321\204\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
