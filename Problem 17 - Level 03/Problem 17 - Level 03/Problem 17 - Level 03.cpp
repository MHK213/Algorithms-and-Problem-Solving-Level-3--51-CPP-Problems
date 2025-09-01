/**
 * @file problem_17_number_exists_in_matrix.cpp
 * @brief Program to check if a number exists in a matrix.
 *
 * The program:
 *  1. Generates a random 3x3 matrix with numbers between 1 and 100.
 *  2. Prompts the user to enter a number.
 *  3. Checks whether the number exists in the matrix.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/**
 * @brief Reads an integer from the user with validation.
 * @return A valid integer entered by the user.
 */
int ReadNumber() {
    int Number = 0;

    cout << "Please Enter a number to look for in matrix? ";
    cin >> Number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

        cout << "Invalid Number, Please enter a valide one?" << endl;

        cin >> Number;
    }

    return Number;
}

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

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << endl;

    int Number = ReadNumber();

    if (IsNumberExist(Matrix, 3, 3, Number))
        cout << "Yes, It's there\n";
    else
        cout << "No, It's Not there\n";

    cout << endl;

    return 0;
}