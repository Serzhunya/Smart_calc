/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_0;
    QPushButton *pushButton_result;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_plus_minus;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_div;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_log;
    QPushButton *pushButton_closed_brace;
    QPushButton *pushButton_opened_brace;
    QPushButton *pushButton_scale;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1229, 588);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 551, 51));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 240, 80, 80));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(100, 240, 80, 80));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setEnabled(true);
        pushButton_9->setGeometry(QRect(190, 240, 80, 80));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_sub = new QPushButton(centralwidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(280, 240, 80, 80));
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 161, 54);\n"
"	border: 0.1px solid grey;\n"
"color: white;\n"
"	font: 18pt \".AppleSystemUIFont\";\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(190, 330, 80, 80));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(100, 330, 80, 80));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 330, 80, 80));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_mul = new QPushButton(centralwidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(280, 330, 80, 80));
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 161, 54);\n"
"	border: 0.1px solid grey;\n"
"color: white;\n"
"	font: 18pt \".AppleSystemUIFont\";\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 420, 80, 80));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 420, 80, 80));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(10, 420, 80, 80));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(242, 82, 208);\n"
"}"));
        pushButton_sum = new QPushButton(centralwidget);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));
        pushButton_sum->setGeometry(QRect(280, 420, 80, 80));
        pushButton_sum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 161, 54);\n"
"	border: 0.1px solid grey;\n"
"color: white;\n"
"	font: 18pt \".AppleSystemUIFont\";\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(190, 510, 81, 71));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1:0, y1:0, y2:1, \n"
"								stop:0 #dadbde, stop:1 #f6f7fa);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(10, 510, 171, 71));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 20pt \".AppleSystemUIFont\";\n"
"	border: 0.5px solid grey;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1:0, y1:0, y2:1, \n"
"								stop:0 #dadbde, stop:1 #f6f7fa);\n"
"}"));
        pushButton_result = new QPushButton(centralwidget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setGeometry(QRect(280, 510, 81, 71));
        pushButton_result->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 161, 54);\n"
"	border: 0.1px solid grey;\n"
"color: white;\n"
"	font: 18pt \".AppleSystemUIFont\";\n"
"}"));
        pushButton_percent = new QPushButton(centralwidget);
        pushButton_percent->setObjectName(QString::fromUtf8("pushButton_percent"));
        pushButton_percent->setGeometry(QRect(190, 150, 80, 80));
        pushButton_percent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 18pt \".AppleSystemUIFont\";\n"
"	background-color: rgb(215, 215, 215);\n"
"border: 0.1px solid grey;\n"
"}"));
        pushButton_plus_minus = new QPushButton(centralwidget);
        pushButton_plus_minus->setObjectName(QString::fromUtf8("pushButton_plus_minus"));
        pushButton_plus_minus->setGeometry(QRect(100, 150, 80, 80));
        pushButton_plus_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 18pt \".AppleSystemUIFont\";\n"
"	background-color: rgb(215, 215, 215);\n"
"border: 0.1px solid grey;\n"
"}"));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(10, 150, 80, 80));
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 13pt \"Helvetica\";\n"
"	font: 22pt \".AppleSystemUIFont\";\n"
"	background-color: rgb(215, 215, 215);\n"
"border: 0.1px solid grey;\n"
"}"));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(280, 150, 80, 80));
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 161, 54);\n"
"	border: 0.1px solid grey;\n"
"color: white;\n"
"	font: 18pt \".AppleSystemUIFont\";\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(370, 240, 121, 81));
        pushButton_mod->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: rgb(219, 110, 208);\n"
"	border: 0.1px solid grey;"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(370, 330, 80, 80));
        pushButton_cos->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(370, 420, 80, 80));
        pushButton_sin->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(370, 509, 80, 71));
        pushButton_tan->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(460, 509, 80, 71));
        pushButton_atan->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(460, 420, 80, 80));
        pushButton_asin->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(460, 330, 80, 80));
        pushButton_acos->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(550, 420, 80, 80));
        pushButton_ln->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(550, 330, 80, 80));
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(550, 509, 80, 71));
        pushButton_log->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: black;\n"
"color: rgb(255, 0, 200);\n"
"	border: 0.1px solid grey;"));
        pushButton_closed_brace = new QPushButton(centralwidget);
        pushButton_closed_brace->setObjectName(QString::fromUtf8("pushButton_closed_brace"));
        pushButton_closed_brace->setGeometry(QRect(510, 150, 121, 81));
        pushButton_closed_brace->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: rgb(219, 110, 208);\n"
"	border: 0.1px solid grey;"));
        pushButton_opened_brace = new QPushButton(centralwidget);
        pushButton_opened_brace->setObjectName(QString::fromUtf8("pushButton_opened_brace"));
        pushButton_opened_brace->setGeometry(QRect(370, 150, 121, 81));
        pushButton_opened_brace->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: rgb(219, 110, 208);\n"
"	border: 0.1px solid grey;"));
        pushButton_scale = new QPushButton(centralwidget);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setGeometry(QRect(509, 240, 121, 81));
        pushButton_scale->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";	\n"
"	background-color: rgb(219, 110, 208);\n"
"	border: 0.1px solid grey;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 541, 51));
        label_2->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(650, 10, 570, 570));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_plus_minus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_closed_brace->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_opened_brace->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_scale->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
