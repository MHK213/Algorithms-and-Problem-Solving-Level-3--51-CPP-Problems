/**
 * @file problem_31_count_letters_match_case.cpp
 * @brief Program to count occurrences of a letter in a string,
 *        with options for case-sensitive and case-insensitive counting.
 *
 * Example:
 *   Input : String = "Hello World"
 *           Letter = 'l'
 *   Output:
 *      Letter 'l' Count = 3
 *      Letter 'l' Or 'L' Count = 3
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
 * @brief Inverts the case of a given character.
 *
 * @param Character The character to invert.
 * @return Lowercase if input was uppercase, uppercase if input was lowercase.
 */
char InvertLetterCase(char Character) {
    return isupper(Character) ? tolower(Character) : toupper(Character);
}

/**
 * @brief Counts how many times a letter appears in a string.
 *
 * @param S1 The input string.
 * @param Letter The character to count.
 * @param MatchCase Whether to count case-sensitively (true) or not (false).
 * @return The number of occurrences of the given character.
 */
short CountLetterInString(string S1, char Letter, bool MatchCase = true) {
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++) {
        if (MatchCase) {
            if (S1[i] == Letter)
                Counter++;
        }
        else {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << endl;

    char Letter = ReadCharacter();

    cout << "\nLetter '" << Letter << "' Count = " << CountLetterInString(S1, Letter) << endl;

    cout << "\nLetter '" << Letter << "' Or '" << InvertLetterCase(Letter) << "' Count = " << CountLetterInString(S1, Letter, false) << endl;

    return 0;
}