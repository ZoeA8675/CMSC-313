#include <stdio.h>
#include <stdlib.h>

// Lines 9-20 is the Add function. The Add function adds 2 matiricies togethier and stores the result in a seperate 2D array.
// The function checks to see if both matricies have the same dimensions. if this condition is not met, the function prints a error
// message and returns nothing. If this condition is met, the function loops though the first matrix and adds each number located 
// in the same location in each matrix with each other. It then sets that result in to the seperate 2D array called 
// result and returns that array.
void Add(int rows1, int columns1, int rows2, int columns2, int** matrix1, int** matrix2, int** result){
    if(rows1 == rows2 && columns1 == columns2){
        for(int i = 0; i < rows1; i++){
            for(int j = 0; j < columns1; j++){
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }else{
        printf("matrices cannot be added -- wrong dimensions! \n");
        return;
    }
}

// Lines 25-31 is the Transpose function. The Transpose function takes a matrix and stores the transposed result in a seperate 2D array.
// The function loops though the first matrix and switches each number's location in the seperate 2D array called result.
// Once all the numbers are filled (loops ends), the function returns the result array.
void Transpose(int rows, int columns, int** matrix1, int**result){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[j][i] = matrix1[i][j];;
        }
    }
}

// Lines 38-45 is the MultiplyC function. The MultiplyC function takes a matrix and stores the result of that matrix multiplied by a constant
// in a seperate 2D array. The function loops though the matrix and multiplies each seperate number within the matrix by the constant.
// Once all the numbers are filled (loops ends), the function returns the result array.
void MultiplyC(int rows, int columns, int constant, int** matrix1, int**result){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            int value = matrix1[i][j] * constant;
            result[i][j] = value;
        }
    }
}

// Lines 5-16 is the Multiply function. The Multiply function multiplies 2 matiricies togethier and stores the result in a seperate 2D array.
// The function checks to see if the number of columns in the first matrix is equal to the number of rows in the second matrix. 
// If this condition is not met, the function prints a error message and returns nothing. If this condition is met, the function 
// loops though the both matricies and multiplies that number located in both matricies togethier. It then sets that 
// result in to the seperate 2D array called result and returns that array.
void Multiply(int rows1, int columns1, int rows2, int columns2, int** matrix1, int** matrix2, int** result){
    if(columns1 == rows2){
        for(int i = 0; i < rows1; i++){
            for(int j = 0; j < columns2; j++){
                result[i][j] = 0;
                for(int h = 0; h < columns1; h++){
                    result[i][j] += matrix1[i][h] * matrix2[h][j];
                }
            }
        }
    }else{
        printf("matries cannot be multiplied -- wrong dimensions!\n");
    }
}

// Lines 74-85 is the Subtract function. The Subtract function subtracts 2 matiricies and stores the result in a seperate 2D array.
// The function checks to see if both matricies have the same dimensions. if this condition is not met, the function prints a error
// message and returns nothing. If this condition is met, the function loops though the first matrix and subtracts each number located 
// in the same location in each matrix with each other. It then sets that result in to the seperate 2D array called 
// result and returns that array.
void Subtract(int rows1, int columns1, int rows2, int columns2, int** matrix1, int** matrix2, int** result){
    if(rows1 == rows2 && columns1 == columns2){
        for(int i = 0; i < rows1; i++){
            for(int j = 0; j < columns1; j++){
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }else{
        printf("matrices cannot be subracted -- wrong dimensions!\n");
        return;
    }
}

// Lines  is the main function. Here is where I allocate memory for all the matricies to test *all* the opperations and check to see 
// if they suceed and fail correctly (Messages are printed where there is an error).
// NOTE: *all* excludes the Transpose and MultiplyC function as they work for any size matrix, so there is no case for an error
int main(){
    //------------------------------------------------SECTION 1: SETUP OF MATRICIES----------------------------------------------------------
    //rows and collumns for Matrix A-F:
    //Matrix A:
    int rows1 = 2;
    int columns1 = 2;
    //Matrix B:
    int rows2 = 2;
    int columns2 = 3;
    //Matrix C:
    int rows3 = 2;
    int columns3 = 3;
    //Matrix D:
    int rows4 = 3;
    int columns4 = 2;
    //Matrix E:
    int rows5 = 4;
    int columns5 = 4;
    //Matrix F:
    int rows6 = 4;
    int columns6 = 4;
    //Matrix G:
    int rows7 = 4;
    int columns7 = 4;

    // accolating memory for Matrix A
    int **matrix_A = malloc(sizeof(int*) * rows1);
    for(int i = 0; i < rows1; i++){
        matrix_A[i] = malloc(sizeof(int) * columns1);
    }
    
    matrix_A[0][0] = 6;
    matrix_A[0][1] = 4;
    matrix_A[1][0] = 8;
    matrix_A[1][1] = 3;

    // accolating memory for Matrix B
    int **matrix_B = malloc(sizeof(int*) * rows2);
    for(int i = 0; i < rows2; i++){
        matrix_B[i] = malloc(sizeof(int) * columns2);
    }

    matrix_B[0][0] = 1;
    matrix_B[0][1] = 2;
    matrix_B[0][2] = 3;
    matrix_B[1][0] = 4;
    matrix_B[1][1] = 5;
    matrix_B[1][2] = 6;

    // accolating memory for Matrix C
    int **matrix_C = malloc(sizeof(int*) * rows3);
    for(int i = 0; i < rows3; i++){
        matrix_C[i] = malloc(sizeof(int) * columns3);
    }

    matrix_C[0][0] = 2;
    matrix_C[0][1] = 4;
    matrix_C[0][2] = 6;
    matrix_C[1][0] = 1;
    matrix_C[1][1] = 3;
    matrix_C[1][2] = 5;

    // accolating memory for Matrix D
    int **matrix_D = malloc(sizeof(int*) * rows4);
    for(int i = 0; i < rows4; i++){
        matrix_D[i] = malloc(sizeof(int) * columns4);
    }

    matrix_D[0][0] = 7;
    matrix_D[0][1] = 3;
    matrix_D[0][2] = 5;
    matrix_D[1][0] = 9;
    matrix_D[1][1] = 1;
    matrix_D[1][2] = 2;

    // accolating memory for Matrix E
    int **matrix_E = malloc(sizeof(int*) * rows5);
    for(int i = 0; i < rows5; i++){
        matrix_E[i] = malloc(sizeof(int) * columns5);
    }

    matrix_E[0][0] = 3;
    matrix_E[0][1] = 4;
    matrix_E[0][2] = 7;
    matrix_E[0][3] = 8;
    matrix_E[1][0] = 1;
    matrix_E[1][1] = 2;
    matrix_E[1][2] = 9;
    matrix_E[1][3] = 2;
    matrix_E[2][0] = 5;
    matrix_E[2][1] = 5;
    matrix_E[2][2] = 1;
    matrix_E[2][3] = 6;
    matrix_E[3][0] = 4;
    matrix_E[3][1] = 8;
    matrix_E[3][2] = 9;
    matrix_E[3][3] = 3;

    // accolating memory for Matrix F
    int **matrix_F = malloc(sizeof(int*) * rows6);
    for(int i = 0; i < rows6; i++){
        matrix_F[i] = malloc(sizeof(int) * columns6);
    }

    matrix_F[0][0] = 2;
    matrix_F[0][1] = 4;
    matrix_F[0][2] = 9;
    matrix_F[0][3] = 8;
    matrix_F[1][0] = 5;
    matrix_F[1][1] = 1;
    matrix_F[1][2] = 8;
    matrix_F[1][3] = 3;
    matrix_F[2][0] = 2;
    matrix_F[2][1] = 1;
    matrix_F[2][2] = 6;
    matrix_F[2][3] = 7;
    matrix_F[3][0] = 9;
    matrix_F[3][1] = 1;
    matrix_F[3][2] = 5;
    matrix_F[3][3] = 2;

    // accolating memory for Matrix G
    int **matrix_G = malloc(sizeof(int*) * rows7);
    for(int i = 0; i < rows7; i++){
        matrix_G[i] = malloc(sizeof(int) * columns7);
    }

    matrix_G[0][0] = 9;
    matrix_G[0][1] = 1;
    matrix_G[0][2] = 3;
    matrix_G[0][3] = 8;
    matrix_G[1][0] = 7;
    matrix_G[1][1] = 2;
    matrix_G[1][2] = 8;
    matrix_G[1][3] = 2;
    matrix_G[2][0] = 4;
    matrix_G[2][1] = 6;
    matrix_G[2][2] = 2;
    matrix_G[2][3] = 5;
    matrix_G[3][0] = 9;
    matrix_G[3][1] = 7;
    matrix_G[3][2] = 6;
    matrix_G[3][3] = 3;
//---------------------------------------------------------SECTION 2: TESTING--------------------------------------------------------------------
    
// TEST 1: PRINTING MATRICIES A-G-------------------------------------------------------------------------------------
// PURPOSE: TO SEE WHAT MATRICIES THAT ARE BEING TESTED AND TO CHECK CORRECT MEMORY ALLOCATION
// PROGRAM WILL RUN AN ERROR IF PRINTING DOES NOT WORK.
//--------------------------------------------------------------------------------------------------------------------
    //printing Matrix A
    printf("TEST 1: PRINTING MATRICIES A-G: \n");
    printf("\n");
    printf("Matrix A: \n");
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < columns1; j++){
            printf("%d ", matrix_A[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing Matrix B
    printf("Matrix B: \n");
    for(int i = 0; i < rows2; i++){
        for(int j = 0; j < columns2; j++){
            printf("%d ", matrix_B[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing Matrix C
    printf("Matrix C: \n");
    for(int i = 0; i < rows3; i++){
        for(int j = 0; j < columns3; j++){
            printf("%d ", matrix_C[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing Matrix D
    printf("Matrix D: \n");
    for(int i = 0; i < rows4; i++){
        for(int j = 0; j < columns4; j++){
            printf("%d ", matrix_D[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing Matrix E
    printf("Matrix E: \n");
    for(int i = 0; i < rows5; i++){
        for(int j = 0; j < columns5; j++){
            printf("%d ", matrix_E[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing Matrix F
    printf("Matrix F: \n");
    for(int i = 0; i < rows6; i++){
        for(int j = 0; j < columns6; j++){
            printf("%d ", matrix_F[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing Matrix G
    printf("Matrix G: \n");
    for(int i = 0; i < rows7; i++){
        for(int j = 0; j < columns7; j++){
            printf("%d ", matrix_G[i][j]);
        }
        printf("\n");
    }

    printf("\n");
//--------------------------------------------------------------------------------------------------------------------
// TEST 2: TRANSPOSING MATRICIES A AND E-------------------------------------------------------------------------------------
// PURPOSE: TO TEST TRANSPOSE FUNCTION ON BIGGER (E) AND SMALLER (A) MATRIX
// PROGRAM WILL RUN AN ERROR IF TRANSPOSE DOES NOT WORK.
//--------------------------------------------------------------------------------------------------------------------
    int rows8 = 2;
    int columns8 = 2;
    int rows9 = 4;
    int columns9 = 4;

    // allocating memory for result1 and result2 to store Transpose results
    int **result1 = malloc(sizeof(int*) * rows8);
    for(int i = 0; i < rows8; i++){
        result1[i] = malloc(sizeof(int) * columns8);
    }

    int **result2 = malloc(sizeof(int*) * rows9);
    for(int i = 0; i < rows9; i++){
        result2[i] = malloc(sizeof(int) * columns9);
    }

    //calling Transpose function on A and E
    Transpose(rows8, columns8, matrix_A, result1);

    Transpose(rows9, columns9, matrix_E, result2);

    //printing result1
    printf("TEST 2: TRANSPOSING MATRICIES: \n");
    printf("A^T: \n");
    for(int i = 0; i < rows8; i++){
        for(int j = 0; j < columns8; j++){
            printf("%d ", result1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing result2
    printf("TEST 2: TRANSPOSING MATRICIES: \n");
    printf("E^T: \n");
    for(int i = 0; i < rows9; i++){
        for(int j = 0; j < columns9; j++){
            printf("%d ", result2[i][j]);
        }
        printf("\n");
    }

    printf("\n");
//--------------------------------------------------------------------------------------------------------------------
// TEST 3: MULTIPLYING MATRICIES B AND F WITH CONSTANTS---------------------------------------------------------------
// PURPOSE: TO TEST MULTIPLYC FUNCTION ON BIGGER (F) AND SMALLER (B) MATRIX
// PROGRAM WILL RUN AN ERROR IF MULTIPLYC DOES NOT WORK.
//--------------------------------------------------------------------------------------------------------------------
    int rows10 = 2;
    int columns10 = 3;
    int rows11 = 4;
    int columns11 = 4;
    int constant = 5;
    int constant2 = 3;

    // allocating memeory for result3 and result4 to store result matricies after bieng multplied by a constant
    int **result3 = malloc(sizeof(int*) * rows10);
    for(int i = 0; i < rows10; i++){
        result3[i] = malloc(sizeof(int) * columns10);
    }

    int **result4 = malloc(sizeof(int*) * rows11);
    for(int i = 0; i < rows11; i++){
        result4[i] = malloc(sizeof(int) * columns11);
    }

    // calling MultiplyC function on B and F to multiply them with 5 and 3
    MultiplyC(rows10, columns10, constant, matrix_B, result3);

    MultiplyC(rows11, columns11, constant2, matrix_F, result4);

    //printing result3
    printf("TEST 3: MULTIPLYING MATRICIES WITH CONSTANTS: \n");
    printf("B * 5: \n");
    for(int i = 0; i < rows10; i++){
        for(int j = 0; j < columns10; j++){
            printf("%d ", result3[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //printing result4
    printf("TEST 3: MULTIPLYING MATRICIES WITH CONSTANTS: \n");
    printf("F * 3: \n");
    for(int i = 0; i < rows11; i++){
        for(int j = 0; j < columns11; j++){
            printf("%d ", result4[i][j]);
        }
        printf("\n");
    }

    printf("\n");
//--------------------------------------------------------------------------------------------------------------------
// TEST 4: MULTIPLYING MATRICIES (PART 1: SUCCESS)---------------------------------------------------------------
// PURPOSE: TO TEST MULTIPLY FUNCTION WITH SUCESSFULL CASE (SAME DIMENSIONS) OF MATRIX C AND D
// PROGRAM SHOULD SUCESSFULY COMPUTE AND PRINT OUT RESULT
//--------------------------------------------------------------------------------------------------------------------
    int rows12 = 2;
    int columns12 = 2;
    
    // allocation memeory for result5 to store the result of C multiplied with D
    int **result5 = malloc(sizeof(int*) * rows12);
    for(int i = 0; i < rows12; i++){
        result5[i] = malloc(sizeof(int) * columns12);
    }

    // calling Multiply with C and D
    Multiply(rows3, columns3, rows4, columns4, matrix_C, matrix_D, result5);

    //printing result5
    printf("TEST 4: MULTIPLYING MATRICIES (PART 1: SUCCESS): \n");
    printf("C * D: \n");
    for(int i = 0; i < rows12; i++){
        for(int j = 0; j < columns12; j++){
            printf("%d ", result5[i][j]);
        }
        printf("\n");
    }

    printf("\n");
//--------------------------------------------------------------------------------------------------------------------
// TEST 4: MULTIPLYING MATRICIES (PART 2: FAILURE)---------------------------------------------------------------
// PURPOSE: TO TEST MULTIPLY FUNCTION WITH FAILING CASE (NOT SAME DIMENSIONS) OF MATRIX A AND G
// PROGRAM SHOULD PRINT OUT ERROR MESSAGE AS A RESULT
//--------------------------------------------------------------------------------------------------------------------
    int rows13 = 2;
    int columns13 = 2;

    // allocating memory for result6 to act as a place to store the result of a failure case
    int **result6 = malloc(sizeof(int*) * rows13);
    for(int i = 0; i < rows13; i++){
        result6[i] = malloc(sizeof(int) * columns13);
    }  
    printf("TEST 4: MULTIPLYING MATRICIES (PART 2: FAILURE): \n");
    // calling Multiply for A and G
    printf("\n");
    Multiply(rows1, columns1, rows7, columns7, matrix_A, matrix_G, result5);
    printf("\n\n");
//--------------------------------------------------------------------------------------------------------------------
// TEST 5: ADDING MATRICIES (PART 1: SUCCESS)---------------------------------------------------------------
// PURPOSE: TO TEST ADD FUNCTION WITH SUCESSFULL CASE (SAME DIMENSIONS) OF MATRIX F AND G
// PROGRAM SHOULD SUCESSFULY COMPUTE AND PRINT OUT RESULT
//--------------------------------------------------------------------------------------------------------------------
    int rows14 = 4;
    int columns14 = 4;
    
    // allocating memory for result7 to store the result of F added with G
    int **result7 = malloc(sizeof(int*) * rows14);
    for(int i = 0; i < rows14; i++){
        result7[i] = malloc(sizeof(int) * columns14);
    }

    // calling the Add function on F and G
    Add(rows6, columns6, rows7, columns7, matrix_F, matrix_G, result7);

    //printing result7
    printf("TEST 5: ADDING MATRICIES (PART 1: SUCCESS): \n");
    printf("F + G: \n");
    for(int i = 0; i < rows14; i++){
        for(int j = 0; j < columns14; j++){
            printf("%d ", result7[i][j]);
        }
        printf("\n");
    }

    printf("\n");

//--------------------------------------------------------------------------------------------------------------------
// TEST 5: ADDING MATRICIES (PART 2: FAILURE)---------------------------------------------------------------
// PURPOSE: TO TEST ADD FUNCTION WITH FAILING CASE (NOT SAME DIMENSIONS) OF MATRIX A AND E
// PROGRAM SHOULD PRINT OUT ERROR MESSAGE AS A RESULT
//--------------------------------------------------------------------------------------------------------------------
    int rows15 = 4;
    int columns15 = 4;

    // allocating memory for result8 to act as a place to store the result of a failure case
    int **result8 = malloc(sizeof(int*) * rows15);
    for(int i = 0; i < rows15; i++){
        result8[i] = malloc(sizeof(int) * columns15);
    }  
    printf("TEST 5: ADDING MATRICIES (PART 2: FAILURE): \n");
    printf("\n");
    // calling the Add function on A and E
    Add(rows1, columns1, rows5, columns5, matrix_A, matrix_E, result8);
    printf("\n\n");
//--------------------------------------------------------------------------------------------------------------------
// TEST 6: SUBTRACTING MATRICIES (PART 1: SUCCESS)---------------------------------------------------------------
// PURPOSE: TO TEST SUBTRACT FUNCTION WITH SUCESSFULL CASE (SAME DIMENSIONS) OF MATRIX F AND G
// PROGRAM SHOULD SUCESSFULY COMPUTE AND PRINT OUT RESULT
//--------------------------------------------------------------------------------------------------------------------
    int rows16 = 4;
    int columns16 = 4;

    // allocated memeory for result9 to store the result of F subtracted with G
    int **result9 = malloc(sizeof(int*) * rows16);
    for(int i = 0; i < rows16; i++){
        result9[i] = malloc(sizeof(int) * columns16);
    }

    // calling the Subtract function on F and G
    Subtract(rows6, columns6, rows7, columns7, matrix_F, matrix_G, result9);

    //printing result9
    printf("TEST 6: SUBTRACTING MATRICIES (PART 1: SUCCESS): \n");
    printf("F - G: \n");
    for(int i = 0; i < rows16; i++){
        for(int j = 0; j < columns16; j++){
            printf("%d ", result9[i][j]);
        }
        printf("\n");
    }

    printf("\n");

//--------------------------------------------------------------------------------------------------------------------
// TEST 6: SUBRACTING MATRICIES (PART 2: FAILURE)---------------------------------------------------------------
// PURPOSE: TO TEST SUBTRACT FUNCTION WITH FAILING CASE (NOT SAME DIMENSIONS) OF MATRIX A AND E
// PROGRAM SHOULD PRINT OUT ERROR MESSAGE AS A RESULT
//--------------------------------------------------------------------------------------------------------------------
    int rows17 = 4;
    int columns17 = 4;

    // allocating memory for result6 to act as a place to store the result of a failure case
    int **result10 = malloc(sizeof(int*) * rows17);
    for(int i = 0; i < rows17; i++){
        result10[i] = malloc(sizeof(int) * columns17);
    }  
    printf("TEST 6: SUBTRACTING MATRICIES (PART 2: FAILURE): \n");
    printf("\n");
    // calling the Subtract function on A and E
    Subtract(rows1, columns1, rows5, columns5, matrix_A, matrix_E, result10);
    printf("\n\n");
//---------------------------------------------------------SECTION 3: CLEAR MEMORY--------------------------------------------------------------------
    
    // Freeing memory from matrix A
    for(int i = 0; i < rows1; i++){
        free(matrix_A[i]);
    }
    free(matrix_A);

    // Freeing memory from matrix B
    for(int i = 0; i < rows2; i++){
        free(matrix_B[i]);
    }
    free(matrix_B);

    // Freeing memory from matrix C
    for(int i = 0; i < rows3; i++){
        free(matrix_C[i]);
    }
    free(matrix_C);

    // Freeing memory from matrix D
    for(int i = 0; i < rows4; i++){
        free(matrix_D[i]);
    }
    free(matrix_D);

    // Freeing memory from matrix E
    for(int i = 0; i < rows5; i++){
        free(matrix_E[i]);
    }
    free(matrix_E);

    // Freeing memory from matrix F
    for(int i = 0; i < rows6; i++){
        free(matrix_F[i]);
    }
    free(matrix_F);

    // Freeing memory from matrix G
    for(int i = 0; i < rows7; i++){
        free(matrix_G[i]);
    }
    free(matrix_G);

    // Freeing memory from result1
    for(int i = 0; i < rows8; i++){
        free(result1[i]);
    }
    free(result1);

    // Freeing memory from result2
    for(int i = 0; i < rows9; i++){
        free(result2[i]);
    }
    free(result2);

    // Freeing memory from result3
    for(int i = 0; i < rows10; i++){
        free(result3[i]);
    }
    free(result3);

    // Freeing memory from result4
    for(int i = 0; i < rows11; i++){
        free(result4[i]);
    }
    free(result4);

    // Freeing memory from result5
    for(int i = 0; i < rows12; i++){
        free(result5[i]);
    }
    free(result5);

    // Freeing memory from result6
    for(int i = 0; i < rows13; i++){
        free(result6[i]);
    }
    free(result6);

    // Freeing memory from result7
    for(int i = 0; i < rows14; i++){
        free(result7[i]);
    }
    free(result7);

    // Freeing memory from result8
    for(int i = 0; i < rows15; i++){
        free(result8[i]);
    }
    free(result8);

    // Freeing memory from result9
    for(int i = 0; i < rows16; i++){
        free(result9[i]);
    }
    free(result9);

    // Freeing memory from result10
    for(int i = 0; i < rows17; i++){
        free(result10[i]);
    }
    free(result10);

    return 0;
}

