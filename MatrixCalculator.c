#include <stdio.h>
#include<stdlib.h>

#define clrscr() system("clear");

#define MAX_SIZE 10


// Declearing Functions
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
int determinant(int matrix[MAX_SIZE][MAX_SIZE], int size);
int traceMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void powerOfMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols, int power);


//Main Function 
int main() {
    int rows, cols;
    int powerA,powerB;

    printf("\n\n\t\t\t--------------------MATRIX CALCULATOR--------------------\n");
    printf("\n\n\t\t\t----------------This Program is written by----------------\n");
    printf("\n\n\t\t\t\t\t\t-Abhishek Kumar\n\n");
    printf("\n\t\t\tYou need to enter 2 matrix A and B for using calculation.\n\n");
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    int matrix_A[MAX_SIZE][MAX_SIZE], matrix_B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("\nEnter elements for Matrix A:\n");
    inputMatrix(matrix_A, rows, cols);

    printf("\nEnter elements for Matrix B:\n");
    inputMatrix(matrix_B, rows, cols);

	clrscr();
    printf("\nMatrix A:\n");
    displayMatrix(matrix_A, rows, cols);

    printf("\nMatrix B:\n");
    displayMatrix(matrix_B, rows, cols);

    int choice;
    do {
		clrscr();
		printf("\nMatrix A:\n");
		displayMatrix(matrix_A, rows, cols);

		printf("\nMatrix B:\n");
		displayMatrix(matrix_B, rows, cols);

        printf("\n________________________________");
        printf("\nOptions:\n\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix A\n");
        printf("5. Transpose Matrix B\n");
        printf("6. Trace of Matrix A\n");
        printf("7. Trace of Matrix B\n");
        printf("8. Determinant of Matrix A\n");
        printf("9. Determinant of Matrix B\n");
        printf("10. Multiply of A^n\n");
        printf("11. Multiply of B^n\n");
        printf("0. Exit\n");
		printf("________________________________");

        printf("\n\nEnter your choice (0-11): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMatrices(matrix_A, matrix_B, result, rows, cols);
                clrscr();
				printf("\nMatrix A:\n");
				displayMatrix(matrix_A, rows, cols);
				printf("\nMatrix B:\n");
				displayMatrix(matrix_B, rows, cols);
                printf("\nResult of Addition:\n");
                displayMatrix(result, rows, cols);
                break;

            case 2:
                subtractMatrices(matrix_A, matrix_B, result, rows, cols);
				clrscr();
				printf("\nMatrix A:\n");
				displayMatrix(matrix_A, rows, cols);
				printf("\nMatrix B:\n");
				displayMatrix(matrix_B, rows, cols);
                printf("\nResult of Subtraction:\n");
                displayMatrix(result, rows, cols);
                break;

            case 3:
                multiplyMatrices(matrix_A, matrix_B, result, rows, cols, cols);
                clrscr();
				printf("\nMatrix A:\n");
				displayMatrix(matrix_A, rows, cols);
				printf("\nMatrix B:\n");
				displayMatrix(matrix_B, rows, cols);
                printf("\nResult of Multiplication:\n");
                displayMatrix(result, rows, cols);
                break;

            case 4:
                transposeMatrix(matrix_A, result, rows, cols);
                clrscr();
				printf("\nMatrix A:\n");
				displayMatrix(matrix_A, rows, cols);
                printf("\nTranspose of Matrix A:\n");
                displayMatrix(result, cols, rows);
                break;

            case 5:
                transposeMatrix(matrix_B, result, rows, cols);
                clrscr();
				printf("\nMatrix B:\n");
				displayMatrix(matrix_B, rows, cols);
                printf("\nTranspose of Matrix B:\n");
                displayMatrix(result, cols, rows);
                break;
            
            case 6:
                clrscr();
				printf("\nMatrix A:\n");
                displayMatrix(matrix_A, rows, cols);
                printf("\nTrace of Matrix A: %d\n", traceMatrix(matrix_A, rows));
                break;

            case 7:
                clrscr();
				printf("\nMatrix B:\n");
                displayMatrix(matrix_B, rows, cols);
                printf("\nTrace of Matrix B: %d\n", traceMatrix(matrix_B, rows));
                break;    

            case 8:
                clrscr();
				printf("\nMatrix A:\n");
                displayMatrix(matrix_A, rows, cols);
                printf("\nDeterminant of Matrix A: %d\n", determinant(matrix_A, rows));
                break;

            case 9:
                clrscr();
				printf("\nMatrix B:\n");
                displayMatrix(matrix_B, rows, cols);
                printf("\nDeterminant of Matrix B: %d\n", determinant(matrix_B, rows));
                break;

            case 10:
                clrscr();
				printf("\nMatrix A:\n");
                displayMatrix(matrix_A, rows, cols);
                printf("Enter the power (n) for matrix A: ");
                scanf("%d", &powerA);
                powerOfMatrix(matrix_A, result, rows, cols, powerA);
                printf("\nResult of A^%d Matrix:\n", powerA);
                displayMatrix(result, rows, cols);

                break;

            case 11:
                clrscr();
				printf("\nMatrix B:\n");
                displayMatrix(matrix_B, rows, cols);
                printf("Enter the power (n) for matrix B: ");
                scanf("%d", &powerB);
                powerOfMatrix(matrix_B, result, rows, cols, powerB);
                printf("\nResult of B^%d Matrix:\n", powerB);
                displayMatrix(result, rows, cols);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("\t\tInvalid choice. Please enter a number between 0 and 11.\n");

        }

        if (choice != 0) {
            printf("\nPress 1 to return to the menu, 0 to exit: ");
            scanf("%d", &choice);
            clrscr();
        }


    } while (choice != 0);

    printf("\t\t\t---------Thanks for using the matrix calculator.---------\n");
    printf("\t\t\t-------follow our github account for more programs.-------\n");
    printf("\t\t\t--------------https://github.com/codingadventure0---------------\n\n");

    return 0;
}


// Function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix elements
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to calculate the trace of a matrix
int traceMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int trace = 0;
    for (int i = 0; i < size; i++) {
        trace += matrix[i][i];
    }
    return trace;
}


// Function to calculate determinant of a matrix
int determinant(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        int det = 0;
        for (int i = 0; i < size; i++) {
            int submatrix[MAX_SIZE][MAX_SIZE];
            for (int j = 1; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    if (k < i) {
                        submatrix[j - 1][k] = matrix[j][k];
                    } else if (k > i) {
                        submatrix[j - 1][k - 1] = matrix[j][k];
                    }	
                }
            }
            int cofactor = matrix[0][i] * determinant(submatrix, size - 1);
            det += ((i % 2 == 0) ? 1 : -1) * cofactor;
        }
        return det;
    }
}



// Function to calculate the power of a matrix A or B
void powerOfMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols, int power) {

    // Initialize result matrix as the identity matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j)
                result[i][j] = 1;
            else
                result[i][j] = 0;
        }
    }

    // Multiply matrix with itself power times
    for (int i = 0; i < power; i++) {
        int temp[MAX_SIZE][MAX_SIZE];
        multiplyMatrices(result, matrix, temp, rows, cols, cols);
        
        for (int m = 0; m < rows; m++) {
            for (int n = 0; n < cols; n++) {
                result[m][n] = temp[m][n];

            }
        }
    }
}

