/*
    Problem 09: Print Middle Row and Column of a Matrix

    Description:
    ------------
    This program generates a 3x3 matrix with random integers (1–10)
    and prints:
      - The middle row.
      - The middle column.

    Logic:
    ------
    Since the matrix is 3x3, the "middle" is simply index 1
    (because indexing starts at 0). For a general NxN matrix, the
    middle is at index (size - 1) / 2.

    Steps:
    ------
    1. Generate a 3x3 matrix with random integers.
    2. Display the entire matrix.
    3. Extract and print the middle row.
    4. Extract and print the middle column.

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
void FilMatrixWithRandomNumbers(int Matrix[][3], int cols, int rows) {
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

// @brief Prints the entire matrix in a formatted way.
void PrintMiddleRow(int Matrix[][3], int rows, int cols) {
    cout << "Middle row of the matrix is: \n";
    for (int i = 0; i < cols; i++) {
        cout << setw(3) << Matrix[(rows - 1) / 2][i] << "   ";
    }
}

// @brief Prints the middle column of the matrix.
void PrintMiddleCol(int Matrix[][3], int rows, int cols) {
    cout << "Middle col of the matrix is: \n";
    for (int i = 0; i < rows; i++) {
        cout << setw(3) << Matrix[i][(cols - 1) / 2] << "   ";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FilMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "The following is a 3X3 random matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << endl;

    PrintMiddleRow(Matrix, 3, 3);
    cout << endl;
    
    PrintMiddleCol(Matrix, 3, 3);
    cout << endl;

    return 0;
}