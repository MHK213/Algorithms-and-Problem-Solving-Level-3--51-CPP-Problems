/**
 * @problem_37_split_string
 * @brief Program to split a string into tokens using a given delimiter.
 *
 * Example:
 *   Input : "Hello,world,this,is,C++"
 *   Delim : ","
 *   Output: ["Hello", "world", "this", "is", "C++"]
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/**
 * @brief Reads a full line of text from the user.
 * @return The input string.
 */
string ReadString() {
    string S1;
    cout << "Please Enter a string? \n";
    getline(cin, S1);

    return S1;
}

/**
 * @brief Splits a string into tokens using a delimiter.
 *
 * @param Text The input string.
 * @param delim The delimiter to split on.
 * @return A vector of tokens (substrings).
 */
vector <string> SplitString(string Text, string delim) {

    vector <string> vString{};
    short pos = 0;
    string sWord;

    while ((pos = Text.find(delim)) != std::string::npos) {
        sWord = Text.substr(0, pos);
        if (sWord != "")
            vString.push_back(sWord);
        Text.erase(0, pos + delim.length());
    }
    if (Text != "")
        vString.push_back(Text);

    return vString;
}

int main()
{
    string S1 = ReadString();
    vector <string> vString = SplitString(S1, " ");
    cout << endl;

    cout << "Tokens: " << vString.size() << endl;

    for (string& Word : vString) {
        cout << Word << endl;
    }

    cout << endl;

    return 0;
}