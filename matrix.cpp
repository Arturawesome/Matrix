#include"matrix.h"
#include<vector>
#include<iostream>
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
Matrix<T>::Matrix(){
    row = 1;
    col = 1;


    std::cout<<"You do not set the numbers of rows and columns: \n"<<"default value: row = 1; col = 1";
}
template<typename T>
Matrix<T>::Matrix(int row_input, int col_input){
    row = row_input;
    col = col_input;
    std::cout<<"You set the numbers of rows =" << row<< " and col = "<< col<<std::endl;

}

template<typename T>
void Matrix<T>:: WriteMatrix(){
    std::cout<<"Write amtrix data by rows with space: ";
    std::string s;
    std::vector<T> row_data;
    int i = 0;
    while(i < row){
        getline(std::cin, s);
        row_data = StringToNumberVector<T>(s);
        if(row_data.size() > col){
            std::cout<<"Amount of numbers is greater then column value";
            continue;
        }
        else{
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
        }
        std::cout<<"\n";
    }
}


int main(){
    Matrix<double> M1(2, 2);
    M1.WriteMatrix();
    M1.ShowMatrix();
    std::cout<<"do some changes";

}
