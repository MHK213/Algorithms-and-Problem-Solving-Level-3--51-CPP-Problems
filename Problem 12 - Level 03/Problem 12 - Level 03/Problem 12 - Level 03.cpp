/**
 * @file problem_12_check_typical_matrices.cpp
 * @brief Program to check if two matrices are "typical" (element-by-element identical).
 *
 * A matrix is considered "typical" here if:
 *  - It has the same dimensions.
 *  - Every element in the same position is exactly equal.
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
 * @brief Checks if two matrices are "typical" (element-by-element equal).
 * @param Matrix1 The first matrix.
 * @param Matrix2 The second matrix.
 * @param rows Number of rows in both matrices.
 * @param cols Number of columns in both matrices.
 * @return True if both matrices are identical element-by-element, otherwise false.
 */
bool areTypicalMatrices(int Matrix1[][3], int Matrix2[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Matrix1[i][j] != Matrix2[i][j])
                return false;
        }
    }
    return true;
}

/**
 * @brief Prints the result of the typical matrix comparison.
 * @param Matrix1 The first matrix.
 * @param Matrix2 The second matrix.
 */
void PrintResult(int Matrix1[][3], int Matrix2[][3]) {
    if (areTypicalMatrices(Matrix1, Matrix2, 3, 3))
        cout << "Yes,Both Matrices are typical\n";
    else
        cout << "No, Matrices are not typical\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << endl;

    PrintResult(Matrix1, Matrix2);
    cout << endl;

    return 0;
}