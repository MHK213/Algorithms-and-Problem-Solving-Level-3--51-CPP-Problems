/**
 * @problem_39_join_string
 * @brief Program to join a vector of strings with a delimiter.
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

int main()
{
    vector <string> vString { "Madi", "Abdelheq", "ProgrammingAdvices" };
    string delim = " ";

    cout << "Vector after join: \n";
    cout << JoinString(vString, delim);

    cout << endl;

    return 0;
}