// Matrix.cpp
#include "Matrix.h"
#include "make_unique.h"
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <fstream>


Matrix::Matrix() {}

Matrix::Matrix(int n) : n(1), m(n), mat(std::make_unique<double[]>(n)) {
    std::fill(mat.get(), mat.get() + m, 0.0);
}

Matrix::Matrix(int n, int m) : n(n), m(m), mat(std::make_unique<double[]>(n * m)) {
    std::fill(mat.get(), mat.get() + n * m, 0.0);
}

Matrix::Matrix(const Matrix &matrix) : n(matrix.n), m(matrix.m),
    mat(std::make_unique<double[]>(n * m)) {
    std::copy(matrix.mat.get(), matrix.mat.get() + n * m, mat.get());
}

Matrix::~Matrix() {}

double &Matrix::operator()(std::size_t x, std::size_t y) {
    if (x >= n || y >= m) throw std::out_of_range("Index out of bounds");
    return mat[x * m + y];
}

const double &Matrix::operator()(std::size_t x, std::size_t y) const {
    if (x >= n || y >= m) throw std::out_of_range("Index out of bounds");
    return mat[x * m + y];
}

void Matrix::fill(double value) {
    std::fill(mat.get(), mat.get() + n * m, value);
}

std::tuple<int, int> Matrix::size() const {
    return std::make_tuple(n, m);
}

int Matrix::length() const {
    return std::max(n, m);
}

double Matrix::max() const {
    return *std::max_element(mat.get(), mat.get() + n * m);
}

double Matrix::min() const {
    return *std::min_element(mat.get(), mat.get() + n * m);
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.n; ++i) {
        for (int j = 0; j < matrix.m; ++j)
            os << std::fixed << std::setprecision(2) << matrix(i, j) << " ";
        os << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Matrix &matrix) {
    is >> matrix.n >> matrix.m;
    matrix.mat = std::make_unique<double[]>(matrix.n * matrix.m);
    for (int i = 0; i < matrix.n * matrix.m; ++i)
        is >> matrix.mat[i];
    return is;
}

bool Matrix::operator==(const Matrix &matrix) const {
    if (n != matrix.n || m != matrix.m) return false;
    for (int i = 0; i < n * m; ++i)
        if (mat[i] != matrix.mat[i]) return false;
    return true;
}

bool Matrix::operator!=(const Matrix &matrix) const {
    return !(*this == matrix);
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix) return *this;
    n = matrix.n;
    m = matrix.m;
    mat = std::make_unique<double[]>(n * m);
    std::copy(matrix.mat.get(), matrix.mat.get() + n * m, mat.get());
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &matrix) {
    if (m != matrix.n)
        throw std::logic_error("[MATRIX] Cannot multiply: incompatible dimensions");

    auto result = std::make_unique<double[]>(n * matrix.m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < matrix.m; ++j) {
            result[i * matrix.m + j] = 0;
            for (int k = 0; k < m; ++k)
                result[i * matrix.m + j] += (*this)(i, k) * matrix(k, j);
        }

    m = matrix.m;
    mat = std::move(result);
    return *this;
}

Matrix &Matrix::operator*=(double a) {
    for (int i = 0; i < n * m; ++i)
        mat[i] *= a;
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &matrix) {
    if (n != matrix.n || m != matrix.m)
        throw std::logic_error("[MATRIX] Cannot add: size mismatch");
    for (int i = 0; i < n * m; ++i)
        mat[i] += matrix.mat[i];
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &matrix) {
    if (n != matrix.n || m != matrix.m)
        throw std::logic_error("[MATRIX] Cannot subtract: size mismatch");
    for (int i = 0; i < n * m; ++i)
        mat[i] -= matrix.mat[i];
    return *this;
}

void Matrix::transpose() {
    auto result = std::make_unique<double[]>(m * n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result[j * n + i] = (*this)(i, j);
    std::swap(n, m);
    mat = std::move(result);
}