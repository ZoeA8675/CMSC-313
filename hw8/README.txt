AUTHORING: 
    Zoe Astifidis, UMBC CMSC 313 Mon/Wed 10am, 04/16/2025

PURPOSE OF SOFTWARE: 
    Software creates matrix library in C and C++ find the result of any matrix equation that involves 
    matrix addition/subraction, scalar matrix multiplication, matrix transposition, and matrix multiplication.
    
FILES: 
    MATRIX.H: helper file for Matrix class in matrix.cpp

    MATRIX.CPP: C++ File that defines functions created in matrix.h 
                and creates Matrix class with functions (Add, Subtract, MultiplyC,
                Multiply, and Transpose), getters and setters (getNum 
                and setNum), constructor and destructor to help allocate memory.  

    MATRIX.C: C File that defines functions for the matrix library (Add, Subtract, MultiplyC, Multiply, 
              and Transpose) in the main function. Creates a matrix by dynamicly allocating a 2D integer array with pointers.
    
    DRIVER.CPP: C++ File that uses matrix.cpp to create Matrix objects using getNum and setNum, call 
                the functions defined in matrix.cpp and compute problems in main function

BUILD INSTRUCTIONS: 
    Step 1: Download all the files. 
    Step 2: Compile and run using commands below:
        For C program:
            Compile: gcc -std=c99 -m32 -o matrix matrix.c 
            Run: ./matrix
        For C++ program:
            Compile: g++ -Wall -o matrix matrix.cpp driver.cpp
            Run: ./matrix

TESTING METHODOLOGY: 
    C++ program(functions, etc) was tested using driver.cpp. 
    C program was tested in main function in matrix.c.

ADDITIONAL INFORMATION: N/A