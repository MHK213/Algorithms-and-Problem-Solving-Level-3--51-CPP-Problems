/*
 * @problem_41_reverse_words_in_string
 * @brief Program to reverse the order of words in a string.
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
    string Text;
    cout << "please enter a string? \n";
    getline(cin, Text);

    return Text;
}

/**
 * @brief Splits a string into words based on a delimiter.
 *
 * @param Text The string to split.
 * @param delim The delimiter used to separate words.
 * @return A vector of words extracted from the string.
 */
vector <string> SplitString(string Text, string delim = " ") {
    short pos = 0;
    string sWord;

    vector <string> vReverseString {};

    while ((pos = Text.find(delim)) != std::string::npos) {
        sWord = Text.substr(0, pos);
        if (sWord != "")
            vReverseString.push_back(sWord);

        Text.erase(0, pos + delim.length());
    }
    if (Text != "")
        vReverseString.push_back(Text);

    return vReverseString;
}

/**
 * @brief Reverses the order of words in a string.
 *
 * @param Text1 The input string.
 * @param delim The delimiter used to separate words.
 * @return A new string with words reversed.
 */
string ReverseWordsInString(string Text1, string delim) {

    string Text = "";

    vector <string> vReverseString = SplitString(Text1);
    vector<string>::reverse_iterator iter;

    for (iter = vReverseString.rbegin(); iter != vReverseString.rend(); ++iter) {
        Text += *iter + delim;
    }

    return Text.substr(0, Text.length() - delim.length());
}

int main()
{
    string Text = ReadString();;

    cout << "\nString after reversing words: \n";
    cout << ReverseWordsInString(Text, " ") << endl;

    return 0;
}