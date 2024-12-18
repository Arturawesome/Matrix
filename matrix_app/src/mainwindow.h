// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>   // standart Qt6 class dedicated
                        // to creating the main window
#include <vector>
#include "matrix.h"



/*
    when mainwindow.ui is created, Qt6 automatically generate the ui_mainwindow.h file with     interface of class.
    For avoiding of interfaces conflict  we put this class in Ui object;
*/
namespace Ui{
    class MainWindow; //
}


// My class for logic of my widnow application/
class MainWindow: public QMainWindow{
    Q_OBJECT // macros for adding the class supporting

public:
    // constructor: QWidjet *parent = nullptr means that MainWindow do not have a parent
    // MainWindow it is parent not a child
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui; //Pointer to object which describe the interface
    int matrix_amount;
    int current_matrix_index;
    std::vector<Matrix<double>> list_of_matrix;

    //renew text in input row_col_data line
    void updatePromt();
    void updateDataWindow(int count, const Matrix<double>& data);
    //clean the input filed of row and conflict
    void cleanInputRowCol();
    void cleanWriteMatrixWindow();


private slots:
    // processing number of matrix
    void onMatrixCountChanged(int cout);
    //Transition for the next matrix
    void onNextButtonClicked();
    //void onMatrixInfoChanged();
    void onWriteButtonClickedSave();

    void onCalculateButtonClicked();

};



#endif // MAINWINDOW_H
