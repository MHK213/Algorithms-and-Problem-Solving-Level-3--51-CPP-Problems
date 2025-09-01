/*
    Problem 05: Sum Each Column in Matrix and Store in Another Array

    Description:
    ------------
    This program generates a 3x3 matrix filled with random integers
    in the range [1, 100]. It calculates the sum of each column and
    stores these sums in a separate array, which is then printed.

    Key Steps:
    ----------
    1. Fill a 3x3 matrix with random numbers.
    2. Display the generated matrix in a formatted way.
    3. Calculate the sum of each column.
    4. Store the sums in a separate 1D array.
    5. Display the array of column sums.

    Author: Madi Abdelheq
    Date: 12/08/2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Generates a random number between From and To
int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

// Fills a 2D array (matrix) with random numbers between 1 and 100
// arr : 2D integer array
// cols : number of columns in the matrix
// rows : number of rows in the matrix
void FillMatrixWithRandomNumbers(int arr[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

// Prints the elements of the matrix in a formatted way
// arr : 2D integer array
// cols : number of columns in the matrix
// rows : number of rows in the matrix
void PrintMatrix(int arr[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

// Calculates the sum of each col in the matrix
int ColSum(int arr[][3], int rows, int colNumber) {
    int Sum = 0;
    for (int row = 0; row < rows; row++) {
        Sum += arr[row][colNumber];
    }
    return Sum;
}

/**
 * @brief Calculates the sum of each column in a matrix and stores it in an array.
 *
 * @param matrix The 2D array.
 * @param colSums The output array containing sums of each column.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 */
void SumMatrixColsInArray(int Matrix[][3], int arr[], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        arr[i] = ColSum(Matrix, rows, i);
    }
}

/**
 * @brief Prints an array containing column sums.
 *
 * @param colSums The array of column sums.
 * @param cols Number of columns (size of the array).
 */
void PrintColSumArray(int arr[], int cols) {
    for (int i = 0; i < cols; i++) {
        cout << "Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    int arr[3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);

    cout << "The following is a 3X3 random matrix: \n";
    PrintMatrix(Matrix, 3, 3);
    cout << endl;

    SumMatrixColsInArray(Matrix, arr, 3, 3);

    cout << "The following are the sum of each col in the matrix: " << endl;
    PrintColSumArray(arr, 3);
    cout << endl;

    return 0;
}