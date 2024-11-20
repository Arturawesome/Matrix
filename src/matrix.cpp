#include"../include/matrix.h"

#include <vector>
#include <iostream>
#include <limits>
#include <sstream> // Include for std::istringstream
// template function for split and convertation of the string
template <typename T2>
std::vector<T2> StringToNumberVector(const std::string& input) {
    std::istringstream iss(input);
    std::vector<T2> numbers;
    T2 number;
    // Reading numbers from thr stream
    while (iss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}


template<typename T>
Matrix<T>::Matrix(): row(1), col(1){
    std::cout<<"You do not set the numbers of rows and columns: \n"<<"default value: row = 1; col = 1\n";
}


template<typename T>
Matrix<T>::Matrix(const Matrix& other): row(other.row), col(other.col),
                                        data(other.data), det(other.det) {}


template<typename T>
Matrix<T>::Matrix(int row_input, int col_input): row(row_input), col(col_input){
    std::cout<<"You set the numbers of rows =" << row<< " and col = "<< col<<std::endl;
}


template<typename T>
void Matrix<T>:: WriteMatrix(){
    std::cout<<"Write amtrix data by rows with space: \n";
    std::string s;
    std::vector<T> row_data;
    int i = 0;
    while(i < row){
        getline(std::cin, s);
        row_data = StringToNumberVector<T>(s);
        if(row_data.size() != col){
            std::cout<<"Amount of numbers is greater or lower then column value, try again\n";
            continue;
        }else{
            data.push_back(row_data);
            ++i;
        }
    }
}


template<typename T>
void Matrix<T>::ShowMatrix(){
    std::cout<<"Your Matrix: \n";
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            std::cout<<data[i][j]<<" ";
        }std::cout<<"\n";
    }std::cout<<"\n";
}

template<typename T>
void Matrix<T>::Transp(){
    std::vector<std::vector<T>> dataT(col, std::vector<T>(row, 0));
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            dataT[j][i] = data[i][j];
        }
    }
    data = dataT;
    int row_old = row;
    row = col;
    col = row_old;

}

template<typename T>
double Matrix<T>:: GetDeterminant(){
    double det = 0;
    if(row != col){
        throw std::invalid_argument("Matrix is not a square matrix\n");
    }
    else{
        struct mid{
            T min_v = std::numeric_limits<T>::max();
            int id_val = 0;
        };
        for(int i = 0; i < row; ++i){
            if(data[i][0] < mid->min_v) {mid->min_v = data[i][0]; mid->id_val = i; }
        }
        std::cout<<mid->min_v<<";; ";


    }

    return det;

}

template<typename T>
Matrix<T> Matrix<T>:: operator *(const auto other){
    Matrix<T> Mult = *this;
    Mult *= other;
    return Mult;
}


template <typename T>
Matrix<T>& Matrix<T>::operator *= (const auto a){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
             data[i][j] *= a;
        }
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>:: operator *= (const Matrix<T>& other){
    std::cout<<"There is a broot force alghoritm for matrix multiplication\n";

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


template<typename T>
Matrix<T>& Matrix<T>:: operator += (const Matrix<T>& other){
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


template<typename T>
Matrix<T> Matrix<T>:: operator +(const Matrix<T>& other){
    Matrix<T> Sum = *this;
    Sum += other;
    return Sum;
}

int main(){
    Matrix<double> M1(3, 3);
    Matrix<double> M2(3, 3);
    Matrix<double> M3;
    M1.WriteMatrix();
    M2.WriteMatrix();

    M1.ShowMatrix();
    M2.ShowMatrix();


    try{
        M1 *= 2;
    }
    catch(const char* error_message){
        std::cout<<error_message;
    }
    M1.ShowMatrix();
    std::cout<<"\n";

    M1.Transp();
    M1.ShowMatrix();


    std::cout<<"\n";
    try{
        M1.ShowMatrix();
        M2.ShowMatrix();
        M1 *= M2;
    }
    catch(const char* error_message){
        std::cout<<error_message;
    }

    M1.ShowMatrix();
    std::cout<<"\n";


    try{
        M1.ShowMatrix();
        M2.ShowMatrix();
        M1 += M2;
    }
    catch(const char* error_message){
        std::cout<<error_message;
    }
    M1.ShowMatrix();


    std::cout<<"\n";
    try{
        M2.ShowMatrix();
        M3 = M2 *2 ;
    }
    catch(const char* error_message){
        std::cout<<error_message;
    }


    std::cout<<"M3:";
    M3.ShowMatrix();

    return 0;


}
