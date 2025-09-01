/**
 * @file problem_14_check_scalar_matrix.cpp
 * @brief Program to check whether a given matrix is a scalar matrix.
 *
 * A scalar matrix is a square matrix in which:
 *  - All diagonal elements are equal (to the same constant value k).
 *  - All non-diagonal elements are 0.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// @brief Generates a random integer between From and To (inclusive).
int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

// @brief Fills a matrix with random integers between 1 and 10.
void FillMatrixWithRandomNumbers(int Matrix[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

// @brief Prints the entire matrix in a formatted way.
void PrintMatrix(int Matrix[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << Matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

/**
 * @brief Checks if a matrix is a scalar matrix.
 * @param Matrix The matrix to check.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @return True if the matrix is a scalar matrix, otherwise false.
 */
bool IsScalarMatrix(int Matrix1[][3], int rows, int cols) {
    int FirstDiagElemement = Matrix1[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == i && Matrix1[i][j] != FirstDiagElemement)
                return false;
            else if (j != i && Matrix1[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * @brief Prints the result of the scalar matrix check.
 * @param Matrix The matrix to check.
 */
void PrintResult(int Matrix1[][3]) {
    if (IsScalarMatrix(Matrix1, 3, 3))
        cout << "Yes, Matrix is Scalar\n";
    else
        cout << "No, Matrix is not Scalar\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3] = { {9, 0, 0}, {0,9,0}, {0,0,9} };

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    PrintResult(Matrix1);
    cout << endl;

    cout << "Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << endl;

    PrintResult(Matrix2);
    cout << endl;

    return 0;
}