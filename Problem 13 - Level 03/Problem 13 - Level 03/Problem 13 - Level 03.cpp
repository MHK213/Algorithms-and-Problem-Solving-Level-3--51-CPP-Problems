/**
 * @file problem_13_check_identity_matrix.cpp
 * @brief Program to check whether a given matrix is an identity matrix.
 *
 * An identity matrix is a square matrix in which:
 *  - All diagonal elements are 1.
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
 * @brief Checks if a matrix is an identity matrix.
 * @param Matrix The matrix to check.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @return True if the matrix is an identity matrix, otherwise false.
 */
bool IsIdentityMatrix(int Matrix1[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == i && Matrix1[i][j] != 1)
                return false;
            else if (j != i && Matrix1[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * @brief Prints the result of the identity matrix check.
 * @param Matrix The matrix to check.
 */
void PrintResult(int Matrix1[][3]) {
    if (IsIdentityMatrix(Matrix1, 3, 3))
        cout << "Yes, Matrix is identity\n";
    else
        cout << "No, Matrix is not identity\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3] = { {1, 0, 0}, {0,1,0}, {0,0,1} };

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