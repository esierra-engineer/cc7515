//
// Created by erick on 4/21/25.
//
// Matrix_test.cpp
#include "../src/Matrix.h"
#include <gtest/gtest.h>

TEST(MatrixTest, testEmptyConstructor) {
    Matrix m{};
    EXPECT_EQ(m.n, 0);
    EXPECT_EQ(m.m, 0);
}
TEST(MatrixTest, testVectorConstructor) {
    Matrix m{3};
    EXPECT_EQ(m.n, 1);
    EXPECT_EQ(m.m, 3);
}
TEST(MatrixTest, testNxmConstructor) {
    Matrix m(2, 3);
    EXPECT_EQ(m.n, 2);
    EXPECT_EQ(m.m, 3);
}
TEST(MatrixTest, testFill) {
    Matrix m(2, 3);
    m.fill(5.0);
    EXPECT_EQ(m(0, 0), 5.0);
    EXPECT_EQ(m(1, 2), 5.0);
}

TEST(MatrixTest, testGet) {
    Matrix m(2, 3);
    EXPECT_EQ(m(1, 1), 0.0);
}

TEST(MatrixTest, testAssign) {
    Matrix m(2, 3);
    m(1, 1) = 5.0;
    EXPECT_EQ(m(1, 1), 5.0);
}

TEST(MatrixTest, testEqual) {
    Matrix a(2, 2), b(2, 2);
    a.fill(1.0);
    b.fill(1.0);
    EXPECT_TRUE(a == b);
}

TEST(MatrixTest, testNotEqual) {
    Matrix a(2, 2), b(2, 2);
    a.fill(1.0);
    b.fill(2.0);
    EXPECT_TRUE(a != b);
}

TEST(MatrixTest, testSum) {
    Matrix a(2, 2), b(2, 2);
    a.fill(1.0);
    b.fill(2.0);
    a += b;
    EXPECT_EQ(a(0, 0), 3.0);
}

TEST(MatrixTest, testSubstract) {
    Matrix a(2, 2), b(2, 2);
    a.fill(1.0);
    b.fill(2.0);
    a -= b;
    EXPECT_EQ(a(0, 0), -1.0);
}

TEST(MatrixTest, testMax) {
    Matrix a(2, 2);
    a.fill(1.0);
    a(1,1) = 10.0;
    EXPECT_EQ(a.max(), 10.0);
}

TEST(MatrixTest, testMin) {
    Matrix a(2, 2);
    a.fill(10.0);
    a(1,1) = 1.0;
    EXPECT_EQ(a.min(), 1.0);
}

TEST(MatrixTest, testTranspose) {
    Matrix a(2, 3);
    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;
    a.transpose();
    EXPECT_EQ(a.n, 3);
    EXPECT_EQ(a.m, 2);
    EXPECT_EQ(a(0, 0), 1);
    EXPECT_EQ(a(1, 0), 2);
    EXPECT_EQ(a(2, 1), 6);
}

TEST(MatrixTest, testMultiplication) {
    Matrix a(2, 3), b(3, 2);
    a.fill(1.0);
    b.fill(2.0);
    a *= b;
    EXPECT_EQ(a.n, 2);
    EXPECT_EQ(a.m, 2);
    EXPECT_EQ(a(0, 0), 6.0);
}

TEST(MatrixTest, testAmplification) {
    Matrix a(3, 2), b(3, 2);
    b.fill(2.0);
    a = b *= 3.0;
    EXPECT_EQ(a(0, 0), 6.0);
}

TEST(MatrixTest, testLength) {
    Matrix a(2, 3), b(3, 2);
    EXPECT_EQ(a.length(), 3);
    EXPECT_EQ(b.length(), 3);
}
