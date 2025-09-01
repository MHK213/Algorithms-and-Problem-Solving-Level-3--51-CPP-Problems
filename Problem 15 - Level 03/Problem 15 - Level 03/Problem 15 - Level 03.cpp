/**
 * @file problem_15_count_number_in_matrix.cpp
 * @brief Program to count the occurrences of a given number in a matrix.
 *
 * The program:
 *  1. Reads a number from the user.
 *  2. Generates a 3x3 matrix filled with random numbers between 1 and 10.
 *  3. Counts how many times the given number appears in the matrix.
 *  4. Displays the result.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/**
 * @brief Reads an integer from the user with validation.
 * @return The validated integer entered by the user.
 */
int ReadNumber() {
    int Number = 0;

    cout << "Please Enter the number to count in matrix? ";
    cin >> Number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

        cout << "Invalid Number, Please enter a valide one?" << endl;

        cin >> Number;
    }

    return Number;
}

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
 * @brief Counts the occurrences of a given number in the matrix.
 * @param Matrix The matrix to search in.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @param NumberToCount The number to search for.
 * @return The count of occurrences of NumberToCount in the matrix.
 */
int CountNumberInMatrix(int Matrix1[][3], int rows, int cols, int NumberToCount) {
    int Count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Matrix1[i][j] == NumberToCount)
                Count++;
        }
    }
    return Count;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], NumberToCount = ReadNumber();

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    cout << "Number " << NumberToCount << " count in matrix is " << CountNumberInMatrix(Matrix1, 3, 3, NumberToCount);
    cout << endl;

    return 0;
}