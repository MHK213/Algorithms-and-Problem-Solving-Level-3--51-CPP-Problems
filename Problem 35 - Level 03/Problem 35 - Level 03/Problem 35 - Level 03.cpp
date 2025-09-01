/**
 *  problem_35_print_each_word
 * @brief Program to print each word of a string on a new line.
 *
 * Example:
 *   Input : "Hello World from C++"
 *   Output:
 *      Hello
 *      World
 *      from
 *      C++
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @brief Reads a full line of text from the user.
 * @return The input string.
 */
string ReadString() {
    string S1;
    cout << "Please Enter a string? \n";
    getline(cin, S1);

    return S1;
}

/**
 * @brief Prints each word in a string on a separate line.
 *
 * @param S1 The input string.
 */
void PrintEachWordInString(string S1) {

    string delim = " ";
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "")
            cout << sWord << endl;
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
        cout << S1 << endl;
}

int main()
{
    string S1 = ReadString();

    cout << endl;

    PrintEachWordInString(S1);

    cout << endl;

    return 0;
}