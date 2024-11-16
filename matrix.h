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
    Matrix(int row_input, int col_input);
    void ShowMatrix();
    void WriteMatrix();

};

#endif
