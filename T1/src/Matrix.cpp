//
// Created by erick on 4/6/25.
//

#include "Matrix.h"
#include <memory>

Matrix::Matrix() : Matrix(1,1){
}

// Constructor, vector like [1xn]
Matrix::Matrix(int n) : _n(n), mat(new double[n]) {
    for (int i = 0; i < _n; ++i) {
        mat[i] = 0.0;
    }
}

// Constructor [nxm], n:rows, m: columns
Matrix::Matrix(int n, int m) : _n(n), _m(m), mat(new double[n * m]) {
    fill(0);
}


Matrix::Matrix(const std::string &filename){
} // Constructor that reads from a file, any format is valid


Matrix::Matrix(const Matrix &
           matrix){
} // Copy constructor, https://www.geeksforgeeks.org/copy-constructor-in-cpp/


Matrix::~Matrix() {
    ;
}

// Set value to (i,j) <row,column>
double& Matrix::operator()(std::size_t x, std::size_t y){
    const int i = x * _m + y;
    return mat[i];
}

const double& Matrix::operator()(std::size_t x, std::size_t y) const{
    const int i = x * _m + y;
    return mat[i];
}

std::ostream &operator<<(std::ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat._n; ++i) {
        for (int j = 0; j < mat._m; ++j) {
            os << mat(i, j) << " ";
        }
        printf("\n");
    }
    return os;
}

std::istream &operator>>(std::istream &is, Matrix &mat) {
    int x,y;
    printf("ingrese tamaño:\n");
    is >> x;
    is >> y;

    mat._n = x;
    mat._m = y;

    const int size = x * y;

    printf("ingrese los valores (%i):\n", size);
    for (int i = 0; i < x * y; ++i) {
        is >> mat.mat[i];
    }

    return is;
}

void Matrix::fill(double value) {
    for (int i = 0; i < _n * _m; ++i) {
        mat[i] = value;
    }
}  // Fill all the matrix with a value

// Dimensions
// matrix, e.g. [2,4], 2 rows, 4 columns
std::tuple<int, int> Matrix::size() const {
    return std::make_tuple(_n, _m);
}

int Matrix::length() const{
       return std::max(_n, _m);
}

double Matrix::max() const {
    double maximum = mat[0];
    for (int i = 1; i < _n * _m; ++i) {
        if (mat[i] > maximum) {
            maximum = mat[i];
        }
    }
    return maximum;
} // Maximum value of the matrix

double Matrix::min() const {
    double minimum = mat[0];
    for (int i = 1; i < _n * _m; ++i) {
        if (mat[i] < minimum) {
            minimum = mat[i];
        }
    }
    return minimum;
} // Minimum value of the matrix

// Booleans
bool operator==(const Matrix &matrix) {
    bool size_condition, values_condition = false;

    return size_condition and values_condition;
} // Equal operator
bool operator!=(const Matrix &matrix) {return false;} // Not equal operator

// Mathematical operation
Matrix &operator=(const Matrix &matrix);  // Assignment operator (copy)
Matrix &operator*=(const Matrix &matrix); // Multiplication
Matrix &operator*=(double a);             // Multiply by a constant
Matrix &operator+=(const Matrix &matrix); // Add
Matrix &operator-=(const Matrix &matrix); // Substract
void transpose();                         // Transpose the matrix