// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMAinWindow>   // standart Qt6 class dedicated
                        // to creating the main window

/*
    when mainwindow.ui is created, Qt6 automatically generate the ui_mainwindow.h file with     interface of class.
    For avoiding of interfaces conflict  we put this class in Ui object;
*/
namespace Ui{
    class MAinWindow; //
}


// My class for logic of my widnow application/
class MainWindow: public QMAinWindow{
    Q_OBJECT
};



#endif // MAINWINDOW_H
