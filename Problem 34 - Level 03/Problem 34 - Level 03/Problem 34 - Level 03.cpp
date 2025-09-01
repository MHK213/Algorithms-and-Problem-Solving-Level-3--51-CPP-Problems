/**
 * problem_34_print_vowels
 * @brief Program to extract and print all vowels from a given string.
 *
 * Example:
 *   Input : "Hello World"
 *   Output: Vowels in string are: e   o   o
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString() {
    string S1;
    cout << "Please Enter a string? \n";
    getline(cin, S1);

    return S1;
}

/**
 * @brief Checks whether a given character is a vowel (case-insensitive).
 *
 * @param Letter The character to check.
 * @return true if the character is a vowel, false otherwise.
 */
bool IsVowel(char Letter) {
    static const char Vowels[] = { 'a', 'e', 'i', 'o', 'u' };

    for (char v : Vowels) {
        if (tolower(Letter) == v)
            return true;
    }

    return false;
}

/*
 * @brief Prints all vowels found in a given string.
 *
 * @param S1 The input string.
 */
void PrintVowelInString(string S1) {

    cout << "\nVowels in string are:   ";
    for (short i = 0; i < S1.length(); i++) {
        if (IsVowel(S1[i]))
            cout << S1[i] << "   ";
    }
}

int main()
{
    string S1 = ReadString();

    PrintVowelInString(S1);

    return 0;
}