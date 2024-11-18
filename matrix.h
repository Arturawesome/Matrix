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
template<typename T>
class Matrix{
private:
    int row, col;
    std::vector<std::vector<T>> data;
    double det;
public:
    Matrix();
    Matrix(const Matrix& other);
    Matrix(int row_input, int col_input);

    void ShowMatrix();
    void WriteMatrix();

    double GetDeterminant();
    Matrix<T>& operator *= (const auto a);
    Matrix<T>& operator *= (const Matrix<T>& other);
    Matrix<T> operator *(const auto other);

    Matrix<T>& operator += (const Matrix<T>& other);
    Matrix<T> operator +(const Matrix<T>& other);


};

#endif
