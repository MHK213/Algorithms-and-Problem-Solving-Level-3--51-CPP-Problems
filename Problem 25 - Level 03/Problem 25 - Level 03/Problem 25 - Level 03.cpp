/**
 * @file problem_25_lower_first_letter_each_word.cpp
 * @brief Program to convert the first letter of each word in a sentence to lowercase.
 *
 * Example:
 *   Input : "C++ Is Very Powerful"
 *   Output: "c++ is very powerful"
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
 * @brief Converts the first letter of each word in the sentence to lowercase.
 *
 * @param Sentence Input sentence.
 * @return Modified sentence with lowercase word starts.
 */
string LowerFirstLetterOfEachWord(string Sentence) {
    bool isFirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++) {
        if (Sentence[i] != ' ' && isFirstLetter)
            Sentence[i] = tolower(Sentence[i]);

        isFirstLetter = (Sentence[i] == ' ' ? true : false);
    }

    return Sentence;
}

int main()
{
    string Sentence = ReadString();

    cout << "Sentence after conversion: \n";
    cout << LowerFirstLetterOfEachWord(Sentence);

    cout << endl;

    return 0;
}