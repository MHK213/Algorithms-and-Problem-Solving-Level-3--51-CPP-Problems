/**
 * @file problem_28_invert_all_letters_case.cpp
 * @brief Program to invert the case of all characters in a string.
 *
 * Example:
 *   Input : "Hello World!"
 *   Output: "hELLO wORLD!"
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


/**
 * @brief Reads a full line of text from the user.
 * @return The input sentence as a string.
 */
string ReadString() {
    string Sentence;
    cout << "Please enter your string: \n";
    getline(cin, Sentence);
    return Sentence;
}

/**
 * @file problem_28_invert_all_letters_case.cpp
 * @brief Program to invert the case of all characters in a string.
 *
 * Example:
 *   Input : "Hello World!"
 *   Output: "hELLO wORLD!"
 */
char InvertLetterCase(char Character) {
    return isupper(Character) ? tolower(Character) : toupper(Character);
}

/**
 * @brief Inverts the case of all characters in a string.
 *
 * @param S1 Input string.
 * @return A new string with all characters inverted.
 */
string InvertAllStringLettersCase(string S1) {
    for (short i = 0; i < S1.length(); i++) {
        S1[i] = InvertLetterCase(S1[i]);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after Inverting All Letters Case:\n";
    cout << InvertAllStringLettersCase(S1) << endl;

    return 0;
}