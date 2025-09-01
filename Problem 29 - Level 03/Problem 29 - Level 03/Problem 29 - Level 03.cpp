/**
 * @file problem_29_count_small_capital_letters.cpp
 * @brief Program to count capital letters, small letters, and total length of a string.
 *
 * Example:
 *   Input : "Hello World!"
 *   Output:
 *     String Length        = 12
 *     Capital Letters Count = 2
 *     Small Letters Count   = 8
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @enum enWhatToCount
 * @brief Defines what kind of characters to count in a string.
 */
enum enWhatToCount { SmallLetter = 1, CapitalLetter = 2, All = 3};

/**
 * @brief Reads a full line of text from the user.
 * @return The input sentence as a string.
 */
string ReadString() {
    string Sentence;
    cout << "Please enter your string: \n";
    getline(cin, Sentence);
    return Sentence;
}

/**
 * @brief Counts specific types of characters in a string.
 *
 * @param S1 The input string.
 * @param WhatToCount Type of characters to count (small, capital, or all).
 * @return The count of characters based on the given criteria.
 */
short CountLetter(string S1, enWhatToCount WhatToCount = All) {
    short Counter = 0;

    if (WhatToCount == enWhatToCount::All)
        return S1.length();
    for (short i = 0; i < S1.length(); i++) {
        if (WhatToCount == enWhatToCount::CapitalLetter && isupper(S1[i]))
            Counter++;
        else if (WhatToCount == enWhatToCount::SmallLetter && islower(S1[i]))
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString Length = " << CountLetter(S1) << endl;

    cout << "Capital Letters Count = " << CountLetter(S1, enWhatToCount::CapitalLetter) << endl;

    cout << "Small Letters Count = " << CountLetter(S1, enWhatToCount::SmallLetter) << endl;

    return 0;
}