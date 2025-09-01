/*
    Problem 06: 3x3 Ordered Matrix

    Description:
    ------------
    This program generates a 3x3 matrix filled with ordered integers
    starting from 1, arranged row by row. The matrix is then displayed
    in a formatted layout.

    Key Steps:
    ----------
    1. Fill a 3x3 matrix with ordered numbers (1 -> 9).
    2. Display the generated matrix in a neat table format.

    Author: Madi Abdelheq
    Date: 13-08-2025
*/

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Fills a 2D matrix with ordered integers starting from 1.
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
 * @brief Prints the contents of a 2D matrix in a formatted layout.
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

int main()
{

    int arr[3][3];

    FilMatrixWithOrderedNumbers(arr, 3, 3);

    cout << "The following is a 3X3 ordered matrix: \n";
    PrintMatrix(arr, 3, 3);
    
    cout << endl;

    return 0;
}