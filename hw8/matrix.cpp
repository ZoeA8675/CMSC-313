//Lines 2-124 is the Matrix class. Along with getters, setters, and constuctors/destructors, the class contains functions to add, subract, 
// transpose and multiply Matrix objects with numbers or with other Matrix objects. Matrix objects are 2D arrays dynamicly allocated with pointers.
#include "matrix.h"
#include <iostream>
using namespace std;

// Lines 8-12 is the default constructor for the Matrix class and creates a empty object. 
Matrix::Matrix() {
    matrix = nullptr;
    rows = 0;
    columns = 0;
}

// Lines 16-22 is the main constructor for the Matrix class. This constructor sets up the Matrix object 
// with the number of rows and columns desired.
Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[columns](); 
}

// Lines 25-39 is the Add function. The Add function takes 2 Matrix objects, adds them togethier, and stores them 
// in a local Matrix object totalMatrix. The function checks first to see if the 2 matrix objects have the same rows and columns
// before adding them. If they do not have the same dimensions, the function prints out a error message and returns an empty object.
// If they do have the same dimensions, the function creates totalMatrix object and uses getNum function to aquire the numbers
// in the same position within each matrix. After finding these numbers, the function adds them together and sets that result in totalMatrix
// using setNum. Once all the numbers are filled in totalMatrix (loop ends), function resturn totalmatrix as a result.
Matrix Matrix::Add(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.rows == matrix2.rows && matrix1.columns == matrix2.columns) {
        Matrix totalMatrix(matrix1.rows, matrix1.columns);
        for (int i = 0; i < matrix1.rows; i++) {
            for (int j = 0; j < matrix1.columns; j++) {
                int sum = matrix1.getNum(i, j) + matrix2.getNum(i, j);
                totalMatrix.setNum(i, j, sum);
            }
        }
        return totalMatrix;
    } else {
        cout << "cannot add -- matrices are not the same dimensions \n" << endl;
        return Matrix();
    }
}

// Lines 52-66 is the Subtract function. The Subtract function takes 2 Matrix objects, subtracts them, and stores them 
// in a local Matrix object totalMatrix. The function checks first to see if the 2 matrix objects have the same rows and columns
// before subtracting them. If they do not have the same dimensions, the function prints out a error message and returns an empty object.
// If they do have the same dimensions, the function creates totalMatrix object and uses getNum function to aquire the numbers
// in the same position within each matrix. After finding these numbers, the function subtracts them and sets that result in totalMatrix
// using setNum. Once all the numbers are filled in totalMatrix (loop ends), function resturn totalmatrix as a result.
Matrix Matrix::Subtract(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.rows == matrix2.rows && matrix1.columns == matrix2.columns) {
        Matrix totalMatrix(matrix1.rows, matrix1.columns);
        for (int i = 0; i < matrix1.rows; i++) {
            for (int j = 0; j < matrix1.columns; j++) {
                int sum = matrix1.getNum(i, j) - matrix2.getNum(i, j);
                totalMatrix.setNum(i, j, sum);
            }
        }
        return totalMatrix;
    } else {
        cout << "cannot subtract -- matrices are not the same dimensions \n" << endl;
        return Matrix();
    }
}

// Lines 69-86 is the Multiply function. The Multiply function takes 2 Matrix function, multiplies them togethier,
// and then stores the result in a local Matrix object totalMatrix. In order to multiply 2 matricies, the function checks first 
// to see if the number of columns in the first Matrix object is equal to the number of rows in the second Matrix object.
// If this condition is not met, the function prints out a error message and returns an empty object. If this condition is met, 
// the function creates totalMatrix object and uses getNum function to aquire the numbers in the same position within each matrix. 
// After finding these numbers, the function loops though the columns in the first Matrix object, multiplies them and sets that result 
// in totalMatrix using setNum. Once all the numbers are filled in totalMatrix (loop ends), function resturn totalmatrix as a result.
Matrix Matrix::Multiply(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.columns == matrix2.rows) {
        Matrix totalMatrix(matrix1.rows, matrix2.columns);
        for (int i = 0; i < matrix1.rows; i++) {
            for (int j = 0; j < matrix2.columns; j++) {
                int sum = 0;
                for (int h = 0; h < matrix1.columns; h++) {
                    sum += matrix1.getNum(i, h) * matrix2.getNum(h, j);
                }
                totalMatrix.setNum(i, j, sum);
            }
        }
        return totalMatrix;
    } else {
        cout << "cannot multiply -- matrices are not the same dimensions \n" << endl;
        return Matrix();
    }
}

// Lines 95-104 is the MultiplyC function. The MultiplyC function multiplies a matrix by a constant integer and then 
// stores the result in a local Matrix object totalMatrix. The function creates the local Matrix object totalMatrix, loops 
// through the matrix to multiply that number with the constant, and then set the result in totalMatrix. Once all the 
// numbers are filled in totalMatrix (loop ends), function resturn totalMatrix as a result.
Matrix Matrix::MultiplyC(const Matrix& matrix1, int constant) {
    Matrix totalMatrix(matrix1.rows, matrix1.columns);
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.columns; j++) {
            int product = matrix1.getNum(i, j) * constant;
            totalMatrix.setNum(i, j, product);
        }
    }
    return totalMatrix;
}

// Lines 110-119 is the Transpose function. The Transpose function takes any matrix and returns a transposed 
// version with the positions switched. The function uses getNum and setNum to aquire the position of each number 
// and set it to its opposite position in the result local Matrix object transposedMatrix. Once all the 
// numbers are filled in transposedMatrix (loop ends), function resturn transposedMatrix as a result.
Matrix Matrix::Transpose(const Matrix& matrix1) {
    Matrix transposedMatrix(matrix1.columns, matrix1.rows);
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.columns; j++) {
            int val = matrix1.getNum(i, j);
            transposedMatrix.setNum(j, i, val);
        }
    }
    return transposedMatrix;
}

// Lines 125-127 is our getter function getNum. The function getNum returns the number that is located in that row and column.
int Matrix::getNum(int row, int col) const {
    return matrix[row][col];
}

// Lines 130-132 is our setter function setNum. The function setNum returns the new value that is located in that row and column.
void Matrix::setNum(int row, int col, int value) {
    matrix[row][col] = value;
}

// Lines 135-142 is the print function. The print function loops though the Matrix object and prints the result
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << getNum(i, j) << " ";
        }
        cout << " " << endl;
    }
}

// Lines 145-154 is the clear function, which clears the Matrix object from memory and sets the pointers to point to nothing
void Matrix::clear() {
    if (matrix != nullptr) {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    matrix = nullptr;
    rows = 0;
    columns = 0;
}

// Lines 157-159 is the deconstructor for the Matrix class. The Deconstructor uses the helper function clear to 
// clear the Matrix object from memory.
Matrix::~Matrix() {
    clear();
}
