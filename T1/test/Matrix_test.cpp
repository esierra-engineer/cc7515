//
// Created by erick on 4/21/25.
//
// Matrix_test.cpp
#include "../src/Matrix.h"
#include <gtest/gtest.h>

TEST(MatrixTest, CreationAndFill) {
    Matrix m(2, 3);
    m.fill(5.0);
    EXPECT_EQ(m(0, 0), 5.0);
    EXPECT_EQ(m(1, 2), 5.0);
}

TEST(MatrixTest, Equality) {
    Matrix a(2, 2), b(2, 2);
    a.fill(1.0);
    b.fill(1.0);
    EXPECT_TRUE(a == b);
}

TEST(MatrixTest, Addition) {
    Matrix a(2, 2), b(2, 2);
    a.fill(1.0);
    b.fill(2.0);
    a += b;
    EXPECT_EQ(a(0, 0), 3.0);
}

TEST(MatrixTest, Transpose) {
    Matrix a(2, 3);
    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;
    a.transpose();
    EXPECT_EQ(std::get<0>(a.size()), 3);
    EXPECT_EQ(std::get<1>(a.size()), 2);
    EXPECT_EQ(a(0, 0), 1);
    EXPECT_EQ(a(1, 0), 2);
    EXPECT_EQ(a(2, 1), 6);
}

TEST(MatrixTest, Multiplication) {
    Matrix a(2, 3), b(3, 2);
    a.fill(1.0);
    b.fill(2.0);
    a *= b;
    EXPECT_EQ(std::get<0>(a.size()), 2);
    EXPECT_EQ(std::get<1>(a.size()), 2);
    EXPECT_EQ(a(0, 0), 6.0);
}
