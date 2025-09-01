/*
 * @problem_36_count_words
 * @brief Program to count the number of words in a string.
 *
 * Example:
 *   Input : "Hello   world  from   C++"
 *   Output: 4
 */

#include <iostream>
#include <string>
#include <cctype>

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
 * @brief Counts the number of words in a string.
 *
 * @param S1 The input string.
 * @return The number of words.
 */
short CountEachWordInString(string S1) {

    short Count = 0;
    string delim = " ";
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "")
            Count++;
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
        Count++;

    return Count;
}

int main()
{
    string S1 = ReadString();

    cout << endl;

    cout << "The Number of words in your string is: " << CountEachWordInString(S1);

    cout << endl;

    return 0;
}