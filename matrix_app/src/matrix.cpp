#include "matrix.h"

#include <vector>
#include <iostream>
#include <limits>
#include <cmath>
#include <sstream> // Include for std::istringstream
// template function for split and convertation of the string
template <typename T>
std::vector<T> StringToNumberVector(const std::string& input) {
    std::istringstream iss(input);
    std::vector<T> numbers;
    T number;
    // Reading numbers from thr stream
    while (iss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

// template<typename T>
// void Matrix<T>::WriteMatrix(QString& matrixData){
//     QStringList lines = matrixData.split("\n", Qt::SkipEmptyParts);
//
//     for(const QString &line: lines){
//         std::vector<double> numbers;
//         //split qtline by spaces. qstring - "in ni " -> qstringlist {"in", "ni"}
//         QStringList elements = line.split(" ", Qt::SkipEmptyParts);
//         for(const QString &el: elements){
//             bool ok;
//             double num = el.toDouble(&ok); // Преобразуем элемент в число
//             numbers.push_back(num);
//         }
//         data.push_back(numbers);
//     }
// }


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






/*
int main(){
    Matrix<double> M1(5, 5);
    Matrix<double> M2(3, 3);
    Matrix<double> M3;
    M1.WriteMatrix();
    M2.WriteMatrix();

    M1.ShowMatrix();
    M2.ShowMatrix();


    try{
        M1 *= 1;
    }
    catch(const char* error_message){
        std::cout<<error_message;
    }
    M1.ShowMatrix();
    std::cout<<"\n";

    //M1.Transp();
    //M1.ShowMatrix();


    // std::cout<<"\n";
    // try{
    //     M1.ShowMatrix();
    //     M2.ShowMatrix();
    //     M1 *= M2;
    // }
    // catch(const char* error_message){
    //     std::cout<<error_message;
    // }
    //
    // M1.ShowMatrix();
    // std::cout<<"\n";
    //
    //
    // try{
    //     M1.ShowMatrix();
    //     M2.ShowMatrix();
    //     M1 += M2;
    // }
    // catch(const char* error_message){
    //     std::cout<<error_message;
    // }
    // M1.ShowMatrix();
    //
    //
    // std::cout<<"\n";
    // try{
    //     M2.ShowMatrix();
    //     M3 = M2 *2 ;
    // }
    // catch(const char* error_message){
    //     std::cout<<error_message;
    // }
    //
    //
    // std::cout<<"M3:";
    // M3.ShowMatrix();

    M1.ShowMatrix();
    double det = M1.GetDeterminant();
    std::cout<<"\n";
    std::cout<<"\n M1.det_val = "<<det<<"\n";

    std::cout<<"\n  after GetDet: \n";
    M1.ShowMatrix();

    return 0;


}
*/
