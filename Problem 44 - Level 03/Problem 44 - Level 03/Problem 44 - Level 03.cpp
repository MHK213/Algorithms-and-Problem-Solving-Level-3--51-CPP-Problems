/**
 * @problem_44_remove_punctuations
 * @brief Program to remove all punctuation characters from a string.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/**
 * @brief Removes all punctuation characters from a string.
 *
 * @param Text The input string.
 * @return A new string without punctuation characters.
 */
string RemovePounctuationsFromString(string Text) {
    string NewString = "";
    for (short i = 0; i < Text.length(); i++) {
        if (!ispunct(Text[i])) {
            NewString += Text[i];
        }
    }

    return NewString;
}

int main()
{
    string Text = "Welcome to Algeria, It's a nice country; it's amazing.\n";

    cout << "Original String: \n" << Text;

    cout << "\nPounctuations Removes: \n";
    cout << RemovePounctuationsFromString(Text) << endl;

    return 0;
}