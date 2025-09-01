/**
 * @file problem_33_count_vowel.cpp
 * @brief Program to count the number of vowels in a given string.
 *
 * Example:
 *   Input : "Hello World"
 *   Output: Number of vowels is: 3
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString() {
    string S1;
    cout << "Please Enter a string? \n";
    getline(cin,S1);

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

/**
 * @brief Counts the number of vowels in a string.
 *
 * @param S1 The input string.
 * @return The count of vowels in the string.
 */
short CountVowelInString(string S1) {
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++) {
            if (IsVowel(S1[i]))
                Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << "\nNumber of vowels is: " << CountVowelInString(S1) << endl;

    return 0;
}