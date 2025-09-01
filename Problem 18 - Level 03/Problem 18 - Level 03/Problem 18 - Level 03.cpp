/**
 * @file problem_18_intersected_numbers_in_matrices.cpp
 * @brief Program to find intersected (common) numbers between two matrices.
 *
 * The program:
 *  1. Generates two random 3x3 matrices with numbers between 1 and 100.
 *  2. Prints both matrices.
 *  3. Finds and prints all numbers that exist in both matrices.
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

/**
 * @brief Fills a matrix with random integers between 1 and 100.
 * @param Matrix The matrix to fill.
 * @param cols Number of columns.
 * @param rows Number of rows.
 */
void FillMatrixWithRandomNumbers(int Matrix[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

/**
 * @brief Prints the entire matrix in a formatted way.
 * @param Matrix The matrix to print.
 * @param cols Number of columns.
 * @param rows Number of rows.
 */
void PrintMatrix(int Matrix[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << Matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

/**
 * @brief Checks if a number exists in the given matrix.
 * @param Matrix The matrix to search in.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param Number The number to look for.
 * @return true if the number exists, false otherwise.
 */
bool IsNumberExist(int Matrix1[][3], int rows, int cols, int Number) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Matrix1[i][j] == Number)
                return true;
        }
    }

    return false;
}

/**
 * @brief Prints all numbers that exist in both matrices.
 * @param Matrix1 The first matrix.
 * @param Matrix2 The second matrix.
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void IntersectedNumbers(int Matrix1[][3], int Matrix2[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (IsNumberExist(Matrix2, 3, 3, Matrix1[i][j]))
                cout << Matrix1[i][j] << " ";
        }
    }
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

    cout << "Intersected Numbers Are: \n";
    IntersectedNumbers(Matrix1, Matrix2, 3, 3);
    
    cout << endl;

    return 0;
}