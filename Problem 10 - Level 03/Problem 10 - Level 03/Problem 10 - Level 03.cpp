/*
    Problem 10: Sum of Matrix

    Description:
    ------------
    This program generates a 3x3 matrix with random integers (1–10)
    and calculates the sum of all its elements.

    Logic:
    ------
    1. Generate a matrix filled with random integers.
    2. Display the matrix in a formatted table.
    3. Loop through all elements, accumulating their values into a sum.
    4. Output the total sum.

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
 * @brief Calculates the sum of all elements in the matrix.
 * @return The total sum of all elements.
 */
int SumOfMatrix(int Matrix[][3], int rows, int cols) {
    int Sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            Sum += Matrix[i][j];
    }
    return Sum;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "The following is a 3X3 random matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << endl;

    cout << "Sum of Matrix is: " << SumOfMatrix(Matrix, 3, 3);
    cout << endl;

    return 0;
}