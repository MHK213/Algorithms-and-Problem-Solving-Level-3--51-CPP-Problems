/**
 * @file problem_26_upper_lower_all_letters.cpp
 * @brief Program to convert all letters of a string to either lowercase or uppercase.
 *
 * Example:
 *   Input : "C++ Is Fun!"
 *   Lower : "c++ is fun!"
 *   Upper : "C++ IS FUN!"
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @brief Reads a full line of text from the user.
 * @return The input sentence as a string.
 */
string ReadString() {
    string Sentence = "";
    cout << "Please Enter your String? \n";
    getline(cin, Sentence);

    return Sentence;
}

/**
 * @brief Converts all letters in the string to lowercase.
 *
 * @param Sentence Input sentence.
 * @return Modified string with all letters in lowercase.
 */
string LowerAllLetters(string Sentence) {

    for (short i = 0; i < Sentence.length(); i++) {
            Sentence[i] = tolower(Sentence[i]);
    }

    return Sentence;
}

/**
 * @brief Converts all letters in the string to uppercase.
 *
 * @param Sentence Input sentence.
 * @return Modified string with all letters in uppercase.
 */
string UpperAllLetters(string Sentence) {

    for (short i = 0; i < Sentence.length(); i++) {
        Sentence[i] = toupper(Sentence[i]);
    }

    return Sentence;
}

int main()
{
    string Sentence = ReadString();

    cout << "\nSentence after Lower: \n";
    cout << LowerAllLetters(Sentence) << endl;

    cout << "\nSentence after Upper: \n";
    cout << UpperAllLetters(Sentence) << endl;

    return 0;
}