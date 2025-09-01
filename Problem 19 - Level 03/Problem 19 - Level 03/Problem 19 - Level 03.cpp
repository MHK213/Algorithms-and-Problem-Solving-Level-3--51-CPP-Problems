/**
 * @file problem_19_min_max_number_in_matrix.cpp
 * @brief Program to find the minimum and maximum number in a matrix.
 *
 * The program:
 *  1. Generates a random 3x3 matrix with numbers between 1 and 100.
 *  2. Prints the matrix.
 *  3. Finds and prints the minimum and maximum numbers in the matrix.
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
 * @brief Finds the minimum number in a given matrix.
 * @param Matrix The matrix to search.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return The minimum number found.
 */
int MinNumberInMatrix(int Matrix1[][3], int rows, int cols) {
    short Min = Matrix1[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Matrix1[i][j] < Min)
                Min = Matrix1[i][j];
        }
    }

    return Min;
}

/**
 * @brief Finds the maximum number in a given matrix.
 * @param Matrix The matrix to search.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return The maximum number found.
 */
int MaxNumberInMatrix(int Matrix1[][3], int rows, int cols) {
    short Max = Matrix1[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Matrix1[i][j] > Max)
                Max = Matrix1[i][j];
        }
    }

    return Max;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    cout << "Minimum Number is: " << MinNumberInMatrix(Matrix1, 3, 3) << endl;

    cout << "Maximum Number is: " << MaxNumberInMatrix(Matrix1, 3, 3);

    cout << endl;

    return 0;
}