/**
 * @file problem_21_fibonacci_series.cpp
 * @brief Program to generate and print the Fibonacci series up to a given length.
 *
 * The Fibonacci series is defined as:
 *   F(0) = 0, F(1) = 1
 *   F(n) = F(n-1) + F(n-2) for n > 1
 *
 * Example (first 10 terms):
 *   1, 1, 2, 3, 5, 8, 13, 21, 34,  55
 */

#include <iostream>

using namespace std;

/**
 * @brief Prints Fibonacci series up to the given length using a loop.
 * @param Length Number of terms to generate.
 */
void PrintFibonacciUsingLoop(int Length) {
    
    int FibonacciNumber = 0;
    int Prev1 = 1, Prev2 = 0;

    cout << "1   ";

    for (short i = 2; i <= Length; i++) {
        FibonacciNumber = Prev1 + Prev2;
        cout << FibonacciNumber << "   ";
        Prev2 = Prev1;
        Prev1 = FibonacciNumber;
    }
}

int main()
{

    PrintFibonacciUsingLoop(10);

    cout << endl;

    return 0;
}