/**
 * @file problem_27_invert_character_case.cpp
 * @brief Program to invert the case of a single character.
 *
 * Example:
 *   Input : 'A'   -> Output: 'a'
 *   Input : 'z'   -> Output: 'Z'
 */

#include <iostream>
#include <string>
#include <cctype>

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
 * @brief Inverts the case of a given character.
 *
 * @param Character Input character.
 * @return The same character with inverted case
 */
char InvertCharacterCase(char Character) {

    return isupper(Character) ? tolower(Character) : toupper(Character);
}

int main()
{
    char Character = ReadCharacter();

    cout << "\nChar After Inverting Case: \n";
    cout << InvertCharacterCase(Character) << endl;

    return 0;
}