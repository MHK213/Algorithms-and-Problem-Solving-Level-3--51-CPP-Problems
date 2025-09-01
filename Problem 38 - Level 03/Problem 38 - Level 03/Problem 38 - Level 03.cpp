/*
 * @problem_38_trim_string
 * @brief Program to trim leading, trailing, or both spaces from a string.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @brief Removes left spaces from a string.
 * @param text Input string.
 * @return A copy of the string with leading spaces removed.
 */
string TrimLeft(string Text) {

    for (short i = 0; i < Text.length(); i++) {
        if (Text[i] != ' ')
            return Text.substr(i, Text.length() - i);
    }

    return "";
}

/**
 * @brief Removes right spaces from a string.
 * @param text Input string.
 * @return A copy of the string with trailing spaces removed.
 */
string TrimRight(string Text) {

    for (short i = Text.length() - 1; i >= 0; i--) {
        if (Text[i] != ' ')
            return Text.substr(0, i + 1);
    }

    return "";
}

/**
 * @brief Removes left and right spaces from a string.
 * @param text Input string.
 * @return A copy of the string with both leading and trailing spaces removed.
 */
string Trim(string Text) {

    return TrimLeft(TrimRight(Text));
}

int main()
{
    string Text = "     Madi Abdelheq    ";
    
    cout << endl;

    cout << "Trim Left : " << TrimLeft(Text) << endl;
    cout << "Trim Right: " << TrimRight(Text) << endl;
    cout << "Trim      : " << Trim(Text) << endl;

    cout << endl;

    return 0;
}