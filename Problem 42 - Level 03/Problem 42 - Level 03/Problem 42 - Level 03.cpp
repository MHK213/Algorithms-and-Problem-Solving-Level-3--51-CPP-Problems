/**
 * @problem_42_replace_words_in_string
 * @brief Program to replace specific words in a string.
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
 * @brief Replaces all occurrences of a specific word in a string.
 *
 * @param Text The input string.
 * @param delim The delimiter used to split/join words.
 * @param StringToReplace The word to replace.
 * @param ReplaceTo The replacement word.
 * @return A new string with replacements applied.
 */
string ReplaceWords(string Text1, string delim, string StringToReplace, string ReplaceTo) {

    string Text = "";
    
    vector <string> vString = SplitString(Text1);
    
    for (string& Word : vString) {
        if (Word == StringToReplace) 
            Word = ReplaceTo;

        Text += Word + delim;
    }

    return Text.substr(0, Text.length() - delim.length());
}

int main()
{
    string Text = "Welcome to Algeria , Algeria is a nice country\n";
    string StringToReplace = "Algeria";
    string ReplaceTo = "Usa";

    cout << "Original String: \n" << Text;

    cout << "\nString after Replace: \n";
    cout << ReplaceWords(Text, " ", StringToReplace, ReplaceTo) << endl;

    return 0;
}