/**
 * @file problem_16_check_sparse_matrix.cpp
 * @brief Program to check if a matrix is sparse.
 *
 * A sparse matrix is defined as one where at least half of its elements are zero.
 *
 * The program:
 *  1. Generates a random 3x3 matrix with numbers between 1 and 100.
 *  2. Checks if it is sparse.
 *  3. Tests the function on a predefined matrix (Matrix2) for verification.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/**
 * @brief Generates a random integer between From and To (inclusive).
 * @param From Lower bound of the random range.
 * @param To Upper bound of the random range.
 * @return A random integer in the given range.
 */
int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

// @brief Fills a matrix with random integers between 1 and 10.
void FillMatrixWithRandomNumbers(int Matrix[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Matrix[i][j] = RandomNumber(1, 100);
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
 * @brief Counts the occurrences of a given number in the matrix.
 * @param Matrix The matrix to search in.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @param NumberToCount The number to search for.
 * @return The count of occurrences of NumberToCount in the matrix.
 */
int CountNumberInMatrix(int Matrix1[][3], int rows, int cols, int NumberToCount) {
    int Count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Matrix1[i][j] == NumberToCount)
                Count++;
        }
    }
    return Count;
}

/**
 * @brief Checks if the given matrix is sparse.
 *
 * A sparse matrix is one where at least half of the elements are zero.
 *
 * @param Matrix The matrix to check.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return true if the matrix is sparse, false otherwise.
 */
bool IsSparseMatrix(int Matrix[][3], int rows, int cols) {
    short MatrixSize = rows * cols;
    
    return (CountNumberInMatrix(Matrix, 3, 3, 0) >= (MatrixSize/2));
    
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3] = {{0, 0, 12}, {0, 0, 1}, {0, 0, 9}};

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "Yes, It's Sparse\n";
    else
        cout << "No, It's Not Sparse\n";

    ;
    cout << endl;

    cout << "Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << endl;

    if (IsSparseMatrix(Matrix2, 3, 3))
        cout << "Yes, It's Sparse\n";
    else
        cout << "No, It's Not Sparse\n";
    cout << endl;

    return 0;
}