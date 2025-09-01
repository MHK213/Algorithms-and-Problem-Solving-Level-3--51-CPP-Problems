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
void FilMatrixWithRandomNumbers(int arr[][3], int cols, int rows) {
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

int ColSum(int arr[][3], int rows, int colNumber) {
    int Sum = 0;
    for (int i = 0; i < rows; i++) {
        Sum += arr[i][colNumber];
    }
    return Sum;
}

void PrintColSumInArray(int Matrix[][3], int arr[], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        cout << "Col " << i + 1 << " Sum = " << ColSum(Matrix, rows, i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    int arr[3];

    FilMatrixWithRandomNumbers(Matrix, 3, 3);

    cout << "The following is a 3X3 random matrix: \n";
    PrintMatrix(Matrix, 3, 3);
    cout << endl;

    cout << "The following are the sum of each col in the matrix: " << endl;
    PrintColSumInArray(Matrix, arr, 3, 3);
    cout << endl;

    return 0;
}