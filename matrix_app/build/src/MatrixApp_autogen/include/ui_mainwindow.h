/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelMatrixCount;
    QSpinBox *spinBoxMatrixCount;
    QLabel *labeRowColInput;
    QLineEdit *lineEditRow;
    QLineEdit *lineEditColumn;
    QPushButton *pushButtonSave;
    QLabel *labeWriteMatrix;
    QPlainTextEdit *plainTextEditMatrixData;
    QPushButton *pushButtonSaveMatrixData;
    QLabel *labelExpressionResult;
    QPlainTextEdit *plainTextEditExpression;
    QPushButton *pushButtonCalculate;
    QTextBrowser *textBrowserAnswer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(740, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelMatrixCount = new QLabel(centralwidget);
        labelMatrixCount->setObjectName("labelMatrixCount");
        labelMatrixCount->setGeometry(QRect(20, 30, 311, 21));
        spinBoxMatrixCount = new QSpinBox(centralwidget);
        spinBoxMatrixCount->setObjectName("spinBoxMatrixCount");
        spinBoxMatrixCount->setGeometry(QRect(20, 60, 45, 29));
        spinBoxMatrixCount->setMinimum(2);
        spinBoxMatrixCount->setMaximum(5);
        labeRowColInput = new QLabel(centralwidget);
        labeRowColInput->setObjectName("labeRowColInput");
        labeRowColInput->setGeometry(QRect(270, 30, 391, 31));
        lineEditRow = new QLineEdit(centralwidget);
        lineEditRow->setObjectName("lineEditRow");
        lineEditRow->setGeometry(QRect(270, 60, 113, 28));
        lineEditColumn = new QLineEdit(centralwidget);
        lineEditColumn->setObjectName("lineEditColumn");
        lineEditColumn->setGeometry(QRect(450, 60, 113, 28));
        pushButtonSave = new QPushButton(centralwidget);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setGeometry(QRect(620, 60, 91, 29));
        labeWriteMatrix = new QLabel(centralwidget);
        labeWriteMatrix->setObjectName("labeWriteMatrix");
        labeWriteMatrix->setGeometry(QRect(20, 120, 231, 31));
        plainTextEditMatrixData = new QPlainTextEdit(centralwidget);
        plainTextEditMatrixData->setObjectName("plainTextEditMatrixData");
        plainTextEditMatrixData->setGeometry(QRect(20, 160, 221, 151));
        pushButtonSaveMatrixData = new QPushButton(centralwidget);
        pushButtonSaveMatrixData->setObjectName("pushButtonSaveMatrixData");
        pushButtonSaveMatrixData->setGeometry(QRect(250, 160, 71, 151));
        labelExpressionResult = new QLabel(centralwidget);
        labelExpressionResult->setObjectName("labelExpressionResult");
        labelExpressionResult->setGeometry(QRect(30, 330, 311, 71));
        plainTextEditExpression = new QPlainTextEdit(centralwidget);
        plainTextEditExpression->setObjectName("plainTextEditExpression");
        plainTextEditExpression->setGeometry(QRect(20, 400, 301, 87));
        pushButtonCalculate = new QPushButton(centralwidget);
        pushButtonCalculate->setObjectName("pushButtonCalculate");
        pushButtonCalculate->setGeometry(QRect(20, 490, 301, 38));
        textBrowserAnswer = new QTextBrowser(centralwidget);
        textBrowserAnswer->setObjectName("textBrowserAnswer");
        textBrowserAnswer->setGeometry(QRect(360, 140, 341, 391));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 740, 34));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelMatrixCount->setText(QCoreApplication::translate("MainWindow", "Numbers of initial matrix:", nullptr));
        labeRowColInput->setText(QCoreApplication::translate("MainWindow", "Write the number of rows and columns in Matrix X", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "Save data", nullptr));
        labeWriteMatrix->setText(QCoreApplication::translate("MainWindow", "Write Matrix 1: row = 1, col = 1", nullptr));
        pushButtonSaveMatrixData->setText(QCoreApplication::translate("MainWindow", "Save \n"
"Matrix\n"
"Data", nullptr));
        labelExpressionResult->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Write the expression for matrix equation</p><p>!!! USE SPACES betwen Operations!!!</p></body></html>", nullptr));
        pushButtonCalculate->setText(QCoreApplication::translate("MainWindow", "Run calculation!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
