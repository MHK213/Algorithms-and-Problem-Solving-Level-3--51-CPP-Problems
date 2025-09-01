/*
    Problem 07: Transpose of a Matrix

    Description:
    ------------
    This program creates a 3x3 matrix filled with ordered numbers (1-> 9),
    then generates a second matrix which is the transpose of the first one.
    The transpose of a matrix is formed by swapping its rows and columns.

    Key Steps:
    ----------
    1. Fill the first matrix with ordered numbers.
    2. Display the original matrix.
    3. Generate the transpose matrix.
    4. Display the transposed matrix.

    Author: Madi Abdelheq
*/

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Fills a matrix with ordered integers starting from 1.
 *
 * @param matrix The 2D array to fill.
 * @param cols Number of columns in the matrix.
 * @param rows Number of rows in the matrix.
 */
void FilMatrixWithOrderedNumbers(int arr[][3], int cols, int rows) {
    int Counter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = Counter;
            Counter++;
        }
    }
}

/**
 * @brief Prints a 2D matrix in a formatted layout.
 *
 * @param matrix The 2D array to print.
 * @param cols Number of columns in the matrix.
 * @param rows Number of rows in the matrix.
 */
void PrintMatrix(int arr[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

/**
 * @brief Generates the transpose of a given matrix.
 *
 * @param source The original matrix.
 * @param destination The resulting transposed matrix.
 * @param cols Number of columns in the source matrix.
 * @param rows Number of rows in the source matrix.
 */
void TransposeMatrix(int Source[][3], int Destination[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Destination[i][j] = Source[j][i];
        }
    }
}

int main()
{

    int arr1[3][3];
    int arr2[3][3];

    FilMatrixWithOrderedNumbers(arr1, 3, 3);

    cout << "The following is a 3X3 ordered matrix: \n";
    PrintMatrix(arr1, 3, 3);

    cout << endl;

    TransposeMatrix(arr1, arr2, 3, 3);

    cout << "The following is the transposed matrix: \n";
    PrintMatrix(arr2, 3, 3);

    cout << endl;

    return 0;
}