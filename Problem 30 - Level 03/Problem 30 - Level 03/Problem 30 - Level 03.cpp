/**
 * @file problem_30_count_letter_in_string.cpp
 * @brief Program to count how many times a specific character appears in a string.
 *
 * Example:
 *   Input : String = "Hello World"
 *           Letter = 'l'
 *   Output: Letter 'l' Count = 3
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
 * @brief Counts how many times a specific character appears in a string.
 *
 * @param S1 The input string.
 * @param Letter The character to count.
 * @return The number of occurrences of the given character.
 */
short CountLetterInString(string S1, char Letter) {
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++) {
        if (S1[i] == Letter)
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << endl;

    char Letter = ReadCharacter();

    cout << "\nLetter '" << Letter << "' Count = " << CountLetterInString(S1, Letter) << endl;

    return 0;
}