/**
 * @problem_43_replace_words_custom
 * @brief Program to replace words in a string with case sensitivity options.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

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

    vector <string> vReverseString{};

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
 * @brief Converts a string to lowercase.
 * @param Text The input string.
 * @return The lowercase version of the string.
 */
string LowerAllString(string Text) {
    for (short i = 0; i < Text.length(); i++) {
        Text[i] = tolower(Text[i]);
    }

    return Text;
}

/**
 * @brief Joins words into a single string with a delimiter.
 *
 * @param vString Vector of words to join.
 * @param delim The delimiter used between words.
 * @return A single concatenated string.
 */
string JoinString(vector <string> vString, string delim) {

    string Text = "";

    for (string& Word : vString) {
        Text += Word + delim;
    }

    return Text.substr(0, Text.length() - delim.length());
}

/**
 * @brief Replaces all occurrences of a word in a string.
 *
 * @param String The input text.
 * @param delim The delimiter used to separate words.
 * @param StringToReplace The word to be replaced.
 * @param ReplaceTo The replacement word.
 * @param MatchCase If true, replacement is case-sensitive; otherwise, case-insensitive.
 * @return A new string with the replacements applied.
 */
string ReplaceWords(string String, string delim, string StringToReplace, string ReplaceTo, bool MatchCase = true) {

    string Text = "";

    vector <string> vString = SplitString(String, delim);
    for (string& Word : vString) {
        if (MatchCase) {
            if (Word == StringToReplace)
                Word = ReplaceTo;
        }
        else {
            if (LowerAllString(Word) == LowerAllString(StringToReplace))
                Word = ReplaceTo;
        }
    }

    return JoinString(vString, delim);
}

int main()
{
    string Text = "Welcome to Algeria , Algeria is a nice country\n";
    string StringToReplace = "algeria";
    string ReplaceTo = "Usa";

    cout << "Original String: \n" << Text;

    cout << "\nReplace With Match Case: \n";
    cout << ReplaceWords(Text, " ", StringToReplace, ReplaceTo) << endl;

    cout << "\nReplace With don't Match Case: \n";
    cout << ReplaceWords(Text, " ", StringToReplace, ReplaceTo, false) << endl;

    return 0;
}