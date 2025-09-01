/**
 * @file problem_23_first_letter_each_word.cpp
 * @brief Program to print the first letter of each word in a given sentence.
 *
 * Example:
 *   Input : "C++ is very powerful"
 *   Output:
 *       C
 *       i
 *       v
 *       p
 */

#include <iostream>
#include <string>

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
 * @brief Prints the first letter of each word in a sentence.
 *
 * @param Sentence The input sentence.
 */
void PrintFirstLetterOfEachWord(string Sentence) {
    bool isFirstLetter = true;
    
    cout << "First Letters of this string: \n";
    for (short i = 0; i < Sentence.length(); i++) {
        if (Sentence[i] != ' ' && isFirstLetter)
            cout << Sentence[i] << endl;

        isFirstLetter = (Sentence[i] == ' ' ? true : false);
    }
}

int main()
{
    string Sentence = ReadString();
    PrintFirstLetterOfEachWord(Sentence);

    cout << endl;

    return 0;
}