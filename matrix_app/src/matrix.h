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
    int Swap(int i_start){
        struct min_and_id{
            T val = std::numeric_limits<T>::min();
            int id_val = 0;
        } mid;
        T dat_val;
        for(int i = i_start; i < row; ++i){
            dat_val = std::abs(data[i][i_start]);
            //std::cout<<dat_val<<"\n";
            if( dat_val > mid.val){
                mid.val = dat_val;
                mid.id_val = i;
            }
        }
        if(i_start != mid.id_val){
            std::swap(data[i_start], data[mid.id_val]);
            return 1;
        }
        return 0;

    }

    double GetDeterminant(){
        std::vector<std::vector<double>> data_h(data);
        double det_help = 1.0;
        int power = 0;

        if(row != col){
            throw std::invalid_argument("Matrix is not a square matrix\n");
        }else{
            double k;
            for(int i = 0; i < row-1; ++i)
            {
                power += Swap(i);
                for(int ii = i+1; ii < row; ++ii){
                    if(std::abs(data[i][i])  < 1e-12) {continue; }
                    k = data[ii][i] / data[i][i];
                    for(int j = 0; j < col; ++j){
                        data[ii][j] = data[ii][j] - data[i][j] * k;
                    }
                }
            }
            det_help = 1.0;
            for(int i = 0; i < row; ++i){
                det_help *= data[i][i];
            }
            det_help *= std::pow(-1, power);
            det = det_help;
        }
        return det_help;
    }


    Matrix<T>& operator *= (const auto a){
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                data[i][j] *= a;
            }
        }
        return *this;
    }


    Matrix<T>& operator *= (const Matrix<T>& other){
        int row_other = other.row;
        int col_other = other.col;
        T mult = 0;
        std::vector<std::vector<T>> mult_data(row, std::vector<T>(col_other, 0));

        if(col != row_other){
            throw std::invalid_argument("N_row(M1) != N_col(M2)\n");
        }else{
            for(int i = 0; i < row; ++i){
                for(int j = 0; j < col_other; ++j){
                    for(int k = 0; k < col; ++k){
                        mult += data[i][k]*other.data[k][j];
                    }
                    mult_data[i][j] = mult;
                    mult = 0;
                }
            }
        }
        data = mult_data;
        row = mult_data.size();
        col = mult_data[0].size();
        return *this;
    }
    Matrix<T> operator *(const auto other){
        Matrix<T> Mult = *this;
        Mult *= other;
        return Mult;
    }


    Matrix<T>&  operator += (const Matrix<T>& other){
        int row_other = other.row;
        int col_other = other.col;
        if(row_other != row ||  col != col_other) {
            std::cout << "Different size of matrix: operation not performed\n" << std::endl;
            throw std::invalid_argument("Matrix dimensions do not match\n");
        }else{
            for(int i = 0; i < row; ++i){
                for(int j = 0; j < col; ++j){
                    data[i][j] += other.data[i][j];
                }
            }
        }
        return *this;
    }

    Matrix<T> operator +(const Matrix<T>& other){
        Matrix<T> Sum = *this;
        Sum += other;
        return Sum;
    }

    Matrix<T>&  operator -= (const Matrix<T>& other){
        int row_other = other.row;
        int col_other = other.col;
        if(row_other != row ||  col != col_other) {
            std::cout << "Different size of matrix: operation not performed\n" << std::endl;
            throw std::invalid_argument("Matrix dimensions do not match\n");
        }else{
            for(int i = 0; i < row; ++i){
                for(int j = 0; j < col; ++j){
                    data[i][j] -= other.data[i][j];
                }
            }
        }
        return *this;
    }

    Matrix<T> operator -(const Matrix<T>& other){
        Matrix<T> Sum = *this;
        Sum -= other;
        return Sum;
    }


};

#endif
