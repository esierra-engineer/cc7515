cmake_minimum_required(VERSION 3.10)
project(T1-CC7515)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Agregar los archivos fuente
add_library(MatrixLib T1/src/Matrix.cpp)

# Test executable
add_executable(MatrixTest T1/test/Matrix_test.cpp)
target_link_libraries(MatrixTest PRIVATE MatrixLib gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(MatrixTest)