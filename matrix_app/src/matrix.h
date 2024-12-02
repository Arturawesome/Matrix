/*
 Progect name: matrix.h / matrix.cpp
 Author name: Artur D.Nasyrov
 Used technologies: OOP, templates
    IN PERSPECTIVE: integration of multithreading and CUDA

 */
#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<iostream>
#include<QMainWindow>

template<typename T>
class Matrix{
private:
    int row, col;
    std::vector<std::vector<T>> data;
    double det;
public:

    Matrix(): row(1), col(1){
        std::cout<<"You do not set the numbers of rows and columns: \n"<<"default value: row = 1; col = 1\n";
    }

    Matrix(const Matrix& other): row(other.row), col(other.col),
    data(other.data), det(other.det) {}

    Matrix(int row_input, int col_input): row(row_input), col(col_input){
        std::cout<<"You set the numbers of rows =" << row<< " and col = "<< col<<std::endl;
    }


    void ShowMatrix(){
        qDebug()<<"In ShowMatrix\n";
        std::cout<<"Your Matrix: \n";
        std::cout<<"row = "<<row<<";  \n";
        std::cout<<"col = "<<col<<";  \n";
        std::cout<<"\n \n";
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                std::cout<<data[i][j]<<" ";
            }std::cout<<"\n";
        }std::cout<<"\n";
    }

    void WriteMatrix();

    void WriteMatrix(QString& matrixData){
        QStringList lines = matrixData.split("\n", Qt::SkipEmptyParts);

        for(const QString &line: lines){
            std::vector<double> numbers;
            //split qtline by spaces. qstring - "in ni " -> qstringlist {"in", "ni"}
            QStringList elements = line.split(" ", Qt::SkipEmptyParts);
            for(const QString &el: elements){
                bool ok;
                double num = el.toDouble(&ok); // Преобразуем элемент в число
                if(ok) numbers.push_back(num);
                qDebug()<<num<<"\n";
            }
            qDebug()<<"\n";
            data.push_back(numbers);
        }
        ShowMatrix();
    }
    int GetRow(){
        return row;
    }
    int GetCol(){
        return col;
    }

    void Transp();
    int Swap(int i_start);
    double GetDeterminant();
    Matrix<T>& operator *= (const auto a);
    Matrix<T>& operator *= (const Matrix<T>& other);
    Matrix<T> operator *(const auto other);

    Matrix<T>& operator += (const Matrix<T>& other);
    Matrix<T> operator +(const Matrix<T>& other);


};

#endif
