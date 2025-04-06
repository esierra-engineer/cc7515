//
// Created by erick on 4/6/25.
//

#include "Matrix.h"

Matrix::Matrix() {
    //
    n = 411;
}

Matrix::Matrix(int n) {

}                       // Constructor, vector like [1xn]


Matrix::Matrix(int n, int m) {

}                // Constructor [nxm], n:rows, m: columns


Matrix::Matrix(const std::string &filename){
} // Constructor that reads from a file, any format is valid


Matrix::Matrix(const Matrix &
           matrix){
} // Copy constructor, https://www.geeksforgeeks.org/copy-constructor-in-cpp/


Matrix::~Matrix() {
    ;
}

std::istream &operator>>(std::istream &is, Matrix &mat) {
    return 0;
}
