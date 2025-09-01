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

bool areEqualMatrices(int Matrix1[][3], int Matrix2[][3], int rows, int cols) {
    return (SumOfMatrix(Matrix1, rows, cols) == SumOfMatrix(Matrix2, rows, cols));
}

void PrintResult(int Matrix1[][3], int Matrix2[][3]) {
    if (areEqualMatrices(Matrix1, Matrix2, 3, 3))
        cout << "Yes,Both Matrices are equal\n";
    else
        cout << "No, Matrices are not equal\n";
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

    PrintResult(Matrix1, Matrix2);
    cout << endl;

    return 0;
}