/**
 * @file problem_24_upper_first_letter_each_word.cpp
 * @brief Program to capitalize the first letter of each word in a sentence.
 *
 * Example:
 *   Input : "c++ is very powerful"
 *   Output: "C++ Is Very Powerful"
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
 * @brief Converts the first letter of each word in the sentence to uppercase.
 *
 * @param Sentence Input sentence.
 * @return Modified sentence with capitalized words.
 */
string UpperFirstLetterOfEachWord(string Sentence) {
    bool isFirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++) {
        if (Sentence[i] != ' ' && isFirstLetter)
            Sentence[i] = toupper(Sentence[i]);

        isFirstLetter = (Sentence[i] == ' ' ? true : false);
    }

    return Sentence;
}

int main()
{
    string Sentence = ReadString();

    cout << "sentence after conversion: \n";
    cout << UpperFirstLetterOfEachWord(Sentence);

    cout << endl;

    return 0;
}