/**
 * @file problem_22_fibonacci_recursion.cpp
 * @brief Program to generate the Fibonacci series using recursion.
 *
 * The Fibonacci sequence is defined as:
 *   F(0) = 0, F(1) = 1
 *   F(n) = F(n-1) + F(n-2) for n > 1
 *
 * Example (first 10 terms):
 *   1, 1, 2, 3, 5, 8, 13, 21, 34
 */

#include <iostream>

using namespace std;

/**
 * @brief Recursively prints Fibonacci numbers.
 *
 * @param Number of terms left to print.
 * @param Prev1 The latest Fibonacci number.
 * @param Prev2 The one before Prev1.
 */
void PrintFibonacciUsingRecursion(int Number, int Prev1, int Prev2) {
    int FibonacciNumber = 0;

    if (Number > 0) {
        FibonacciNumber = Prev1 + Prev2;
        cout << FibonacciNumber << "   ";
        Prev2 = Prev1;
        Prev1 = FibonacciNumber;
        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
    }
}

int main()
{

    PrintFibonacciUsingRecursion(10, 0, 1);

    cout << endl;

    return 0;
}