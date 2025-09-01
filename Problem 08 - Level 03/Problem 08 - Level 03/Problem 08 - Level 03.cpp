#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

void FilMatrixWithRandomNumbers(int Matrix[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int Matrix[][3], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << Matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void MultiplyMatrix(int Matrix1[][3], int Matrix2[][3], int MatrixResult[][3], int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];

    FilMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "The following is a 3X3 random matrix: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << endl;

    FilMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "The following is a 3X3 random matrix: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << endl;

    MultiplyMatrix(Matrix1, Matrix2, MatrixResult, 3, 3);

    cout << "Results : \n";
    PrintMatrix(MatrixResult, 3, 3);

    cout << endl;

    return 0;
}