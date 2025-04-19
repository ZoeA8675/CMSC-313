#include <iostream>
#include "matrix.h"
using namespace std;
// Lines 7-193 is the main function. Here is where I create all the Matrix objects to test *all* the opperations and check to see 
// if they suceed and fail correctly (Messages are printed where there is an error).
// NOTE: *all* excludes the Transpose and MultiplyC function as they work for any size matrix, so there is no case for an error
int main() {
//------------------------------------------------SECTION 1: SETUP OF MATRICIES----------------------------------------------------------
    
    // accolating memory for Matrix A
    Matrix A(2, 2);
    A.setNum(0, 0, 6); A.setNum(0, 1, 4);
    A.setNum(1, 0, 8); A.setNum(1, 1, 3);

    // accolating memory for Matrix B
    Matrix B(2, 3);
    B.setNum(0, 0, 1); B.setNum(0, 1, 2); B.setNum(0, 2, 3);
    B.setNum(1, 0, 4); B.setNum(1, 1, 5); B.setNum(1, 2, 6);
    
    // accolating memory for Matrix C
    Matrix C(2, 3);
    C.setNum(0, 0, 2); C.setNum(0, 1, 4); C.setNum(0, 2, 6);
    C.setNum(1, 0, 1); C.setNum(1, 1, 3); C.setNum(1, 2, 5);
    
    // accolating memory for Matrix D
    Matrix D(3,2);
    D.setNum(0, 0, 7); D.setNum(0, 1, 3); D.setNum(2, 0, 5);
    D.setNum(1, 0, 9); D.setNum(1, 1, 1); D.setNum(2, 1, 2);

    // accolating memory for Matrix E
    Matrix E(4,4);
    E.setNum(0, 0, 3); E.setNum(0, 1, 4); E.setNum(0, 2, 7); E.setNum(0, 3, 8);
    E.setNum(1, 0, 1); E.setNum(1, 1, 2); E.setNum(1, 2, 9); E.setNum(1, 3, 2);
    E.setNum(2, 0, 5); E.setNum(2, 1, 5); E.setNum(2, 2, 1); E.setNum(2, 3, 6);
    E.setNum(3, 0, 4); E.setNum(3, 1, 8); E.setNum(3, 2, 9); E.setNum(3, 3, 3);

    // accolating memory for Matrix F
    Matrix F(4,4);
    F.setNum(0, 0, 2); F.setNum(0, 1, 4); F.setNum(0, 2, 9); F.setNum(0, 3, 8);
    F.setNum(1, 0, 5); F.setNum(1, 1, 1); F.setNum(1, 2, 8); F.setNum(1, 3, 3);
    F.setNum(2, 0, 2); F.setNum(2, 1, 1); F.setNum(2, 2, 6); F.setNum(2, 3, 7);
    F.setNum(3, 0, 9); F.setNum(3, 1, 1); F.setNum(3, 2, 5); F.setNum(3, 3, 2);

    // accolating memory for Matrix G
    Matrix G(4,4);
    G.setNum(0, 0, 9); G.setNum(0, 1, 1); G.setNum(0, 2, 3); G.setNum(0, 3, 8);
    G.setNum(1, 0, 7); G.setNum(1, 1, 2); G.setNum(1, 2, 8); G.setNum(1, 3, 2);
    G.setNum(2, 0, 4); G.setNum(2, 1, 6); G.setNum(2, 2, 2); G.setNum(2, 3, 5);
    G.setNum(3, 0, 9); G.setNum(3, 1, 7); G.setNum(3, 2, 6); G.setNum(3, 3, 3);

//---------------------------------------------------------SECTION 2: TESTING--------------------------------------------------------------------
    
// TEST 1: PRINTING MATRICIES A-G-------------------------------------------------------------------------------------
// PURPOSE: TO SEE WHAT MATRICIES THAT ARE BEING TESTED AND TO CHECK CORRECT MEMORY ALLOCATION
// PROGRAM WILL RUN AN ERROR IF PRINTING DOES NOT WORK.
//--------------------------------------------------------------------------------------------------------------------
    cout << "TEST 1: PRINTING MATRICIES A-G: \n" << endl;

    cout << "Matrix A: " << endl;
    A.print();
    cout << "\n" << endl;

    cout << "Matrix B: " << endl;
    B.print();
    cout << "\n" << endl;

    cout << "Matrix C: " << endl;
    C.print();
    cout << "\n" << endl;

    cout << "Matrix D: " << endl;
    D.print();
    cout << "\n" << endl;

    cout << "Matrix E: " << endl;
    E.print();
    cout << "\n" << endl;

    cout << "Matrix F: " << endl;
    F.print();
    cout << "\n" << endl;

    cout << "Matrix G: " << endl;
    G.print();
    cout << "\n" << endl;

//--------------------------------------------------------------------------------------------------------------------
// TEST 2: TRANSPOSING MATRICIES A AND E-------------------------------------------------------------------------------------
// PURPOSE: TO TEST TRANSPOSE FUNCTION ON BIGGER (E) AND SMALLER (A) MATRIX
// PROGRAM WILL RUN AN ERROR IF TRANSPOSE DOES NOT WORK.
//--------------------------------------------------------------------------------------------------------------------

    // Calling the Transpose function on Matricies A and E
    Matrix AT = A.Transpose(A);
    Matrix ET = E.Transpose(E);

    cout << "TEST 2: TRANSPOSING MATRICIES A AND E: \n" << endl;
    // printing A transposed
    cout << "A transposed: \n" << endl;
    AT.print();
    cout << "\n" << endl;
    // printing E transposed
    cout << "E transposed: \n" << endl;
    ET.print();
    cout << "\n" << endl;
    
//--------------------------------------------------------------------------------------------------------------------
// TEST 3: MULTIPLYING MATRICIES B AND F WITH CONSTANTS---------------------------------------------------------------
// PURPOSE: TO TEST MULTIPLYC FUNCTION ON BIGGER (F) AND SMALLER (B) MATRIX
// PROGRAM WILL RUN AN ERROR IF MULTIPLYC DOES NOT WORK.
//--------------------------------------------------------------------------------------------------------------------
    // calling MultiplyC B with 4
    Matrix result = B.MultiplyC(B, 4);
    // calling MultiplyC F with 8
    Matrix result2 = F.MultiplyC(F, 8);

    cout << "TEST 3: MULTIPLYING MATRICIES B AND F WITH CONSTANTS: \n" << endl;

    // printing B * 4
    cout << "(4 * B) equals: \n" << endl;
    result.print();

    cout << "\n" << endl;

    // printing F * 8
    cout << "(8 * F) equals: \n" << endl;
    result2.print();

    cout << "\n" << endl;

//--------------------------------------------------------------------------------------------------------------------
// TEST 4: MULTIPLYING MATRICIES (PART 1: SUCCESS)---------------------------------------------------------------
// PURPOSE: TO TEST MULTIPLY FUNCTION WITH SUCESSFULL CASE (SAME DIMENSIONS) OF MATRIX C AND D
// PROGRAM SHOULD SUCESSFULY COMPUTE AND PRINT OUT RESULT
//--------------------------------------------------------------------------------------------------------------------
    //calling MultiplyC with C and D
    Matrix result3 = C.Multiply(C, D);

    cout << "TEST 4: MULTIPLYING MATRICIES (PART 1: SUCCESS): \n" << endl;

    //printing C * D
    cout << "(C * D) equals: \n" << endl;
    result3.print();

    cout << "\n" << endl;
    
//--------------------------------------------------------------------------------------------------------------------
// TEST 4: MULTIPLYING MATRICIES (PART 2: FAILURE)---------------------------------------------------------------
// PURPOSE: TO TEST MULTIPLY FUNCTION WITH FAILING CASE (NOT SAME DIMENSIONS) OF MATRIX A AND G
// PROGRAM SHOULD PRINT OUT ERROR MESSAGE AS A RESULT
//--------------------------------------------------------------------------------------------------------------------

    cout << "TEST 4: MULTIPLYING MATRICIES (PART 2: FAILURE): \n" << endl;

    // calling Multiply function on A and G
    Matrix result4 = A.Multiply(A, G);

    cout << "\n" << endl;
//--------------------------------------------------------------------------------------------------------------------
// TEST 5: ADDING MATRICIES (PART 1: SUCCESS)---------------------------------------------------------------
// PURPOSE: TO TEST ADD FUNCTION WITH SUCESSFULL CASE (SAME DIMENSIONS) OF MATRIX F AND G
// PROGRAM SHOULD SUCESSFULY COMPUTE AND PRINT OUT RESULT
//--------------------------------------------------------------------------------------------------------------------
    // calling the Add function on F and G
    Matrix result5 = F.Add(F, G);

    cout << "TEST 5: ADDING MATRICIES (PART 1: SUCCESS): \n" << endl;

    // printing F + G
    cout << "(F + G) equals: \n" << endl;
    result5.print();

    cout << "\n" << endl;
//--------------------------------------------------------------------------------------------------------------------
// TEST 5: ADDING MATRICIES (PART 2: FAILURE)---------------------------------------------------------------
// PURPOSE: TO TEST ADD FUNCTION WITH FAILING CASE (NOT SAME DIMENSIONS) OF MATRIX A AND E
// PROGRAM SHOULD PRINT OUT ERROR MESSAGE AS A RESULT
//--------------------------------------------------------------------------------------------------------------------
    cout << "TEST 5: ADDING MATRICIES (PART 2: FAILURE): \n" << endl;

    // calling the Add function on A and E
    Matrix result6 = A.Add(A, E);

    cout << "\n" << endl;
//--------------------------------------------------------------------------------------------------------------------
// TEST 6: SUBTRACTING MATRICIES (PART 1: SUCCESS)---------------------------------------------------------------
// PURPOSE: TO TEST SUBTRACT FUNCTION WITH SUCESSFULL CASE (SAME DIMENSIONS) OF MATRIX F AND G
// PROGRAM SHOULD SUCESSFULY COMPUTE AND PRINT OUT RESULT
//--------------------------------------------------------------------------------------------------------------------
    // calling the Subtract function on F and G
    Matrix result7 = F.Subtract(F, G);

    cout << "TEST 6: SUBTRACTING MATRICIES (PART 1: SUCCESS): \n" << endl;

    // printing F - G
    cout << "(F - G) equals: \n" << endl;
    result7.print();

    cout << "\n" << endl;
//--------------------------------------------------------------------------------------------------------------------
// TEST 6: SUBRACTING MATRICIES (PART 2: FAILURE)---------------------------------------------------------------
// PURPOSE: TO TEST SUBTRACT FUNCTION WITH FAILING CASE (NOT SAME DIMENSIONS) OF MATRIX A AND E
// PROGRAM SHOULD PRINT OUT ERROR MESSAGE AS A RESULT
//--------------------------------------------------------------------------------------------------------------------
    cout << "TEST 6: MULTIPLYING MATRICIES (PART 2: FAILURE): \n" << endl;

    // calling the Subtract function on A and E
    Matrix result8 = A.Subtract(A, E);

    cout << "\n" << endl;

    return 0;
}