/**
 * @file problem_32_is_vowel.cpp
 * @brief Program to check if a given character is a vowel (a, e, i, o, u).
 *
 * Example:
 *   Input : 'E'
 *   Output: Yes Letter 'E' is vowel
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/**
 * @brief Reads a single character from the user.
 * @return The input character.
 */
char ReadCharacter() {
    char Character;
    cout << "Please Enter a character? \n";
    cin >> Character;

    return Character;
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

int main()
{

    char Letter = ReadCharacter();

    if (IsVowel(Letter))
        cout << "\nYes Letter '" << Letter << "' is vowel\n";
    else
        cout << "\nNo Letter '" << Letter << "' is Not vowel\n";

    return 0;
}