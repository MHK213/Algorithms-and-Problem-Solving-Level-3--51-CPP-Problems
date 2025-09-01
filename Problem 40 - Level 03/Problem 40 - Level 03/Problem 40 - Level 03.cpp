/**
 * @problem_40_join_string_overloading
 * @brief Demonstrates function overloading to join strings from a vector or array.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/**
 * @brief Joins a vector of strings into a single string with a delimiter.
 *
 * @param vString Vector of words to join.
 * @param delim The delimiter to insert between words.
 * @return A single string with words joined by the delimiter.
 */
string JoinString(vector <string> vString, string delim) {

    string Text = "";

    for (string& Word : vString) {
        Text += Word + delim;
    }

    return Text.substr(0, Text.length() - delim.length());
}

/**
 * @brief Joins a fixed-size array of strings into a single string with a delimiter.
 *
 * @param arrString Array of strings.
 * @param length Number of elements in the array.
 * @param delim The delimiter to insert between words.
 * @return A single string with words joined by the delimiter.
 */
string JoinString(string arrString[], short length, string delim) {

    string Text = "";

    for (short i = 0; i < length; i++) {
        Text += arrString[i] + delim;
    }

    return Text.substr(0, Text.length() - delim.length());
}

int main()
{
    vector <string> vString{ "Madi", "Abdelheq", "ProgrammingAdvices" };
    string arrString[] = { "Madi", "Abdelheq", "C++", "Developer" };
    string delim = " ";

    cout << "Vector after join: \n";
    cout << JoinString(vString, delim) << endl;;

    cout << "\nArray after join: \n";
    cout << JoinString(arrString, 4, delim) << endl;;

    return 0;
}