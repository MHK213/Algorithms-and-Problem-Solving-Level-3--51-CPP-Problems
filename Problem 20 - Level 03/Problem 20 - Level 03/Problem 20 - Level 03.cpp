/**
 * @file problem_20_is_palindrome_matrix.cpp
 * @brief Program to check if a matrix is a palindrome matrix.
 *
 * A matrix is considered a palindrome if each row reads the same
 * from left to right and right to left (i.e., horizontally symmetric).
 *
 * Example:
 *   1  2  1
 *   5  5  5
 *   7  3  7
 * is a palindrome matrix.
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
 * @brief Checks whether the given matrix is a palindrome matrix.
 *
 * A palindrome matrix is defined as one where each row is symmetric,
 * meaning Matrix[i][j] == Matrix[i][cols - 1 - j].
 *
 * @param Matrix The matrix to check.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return true if the matrix is palindrome, false otherwise.
 */
bool IsPalindromeMatrix(int Matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            if (Matrix[i][j] != Matrix[i][cols - 1 - j])
                return false;
        }
    }

    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 7} };

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << "Yes, Matrix is Palindrome\n";
    else 
        cout << "No, Matrix is Not Palindrome\n";

    cout << endl;

    cout << "Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << endl;

    if (IsPalindromeMatrix(Matrix2, 3, 3))
        cout << "Yes, Matrix is Palindrome\n";
    else
        cout << "No, Matrix is Not Palindrome\n";

    return 0;
}