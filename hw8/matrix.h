
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
using namespace std;
// Lines 8-28 define the Matrix class and all the function within the class. All the operation functions are marked static to ensure that the 
// information cannot be changed or manipulated in order to enforce encapsulation. The data structure for the Matrix object is also 
// defined in this file. The structure is a dynamic 2D array using pointers.
class Matrix{
public:
    Matrix(); 
    Matrix(int rows, int columns);
    static Matrix Add(const Matrix& matrix1, const Matrix& matrix2);
    static Matrix Subtract(const Matrix& matrix1, const Matrix& matrix2);
    static Matrix Multiply(const Matrix& matrix1, const Matrix& matrix2);
    static Matrix Transpose(const Matrix& matrix);
    static Matrix MultiplyC(const Matrix& matrix, int constant);
    int getNum(int row, int column) const;
    void setNum(int row, int column, int value);
    void print() const;
    ~Matrix();
    void clear(); 

private:
    int rows;
    int columns;
    int ** matrix;     
   
};
#endif