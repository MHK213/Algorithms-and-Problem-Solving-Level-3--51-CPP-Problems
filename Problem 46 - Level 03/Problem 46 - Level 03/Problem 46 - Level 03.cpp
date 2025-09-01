//Problem 46 – Convert Line Data to Record

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @struct stClientData
 * @brief Holds all necessary client information.
 */
struct stClientData {
	string AccountNumber, PinCode, FullName, PhoneNumber;
	double AccountBalance;
};

/**
 * @brief Splits a string into parts using a given delimiter.
 *
 * @param Text The string to split.
 * @param delim The delimiter string.
 * @return vector<string> A vector containing the separated words/fields.
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

/**
 * @brief Converts a line of client data into a structured record.
 *
 * The line must be formatted with fields separated by the given separator.
 *
 * @param Line A single line containing client information.
 * @param Seperator The string used to separate fields (default = "#//#").
 * @return stClientData A structured client record.
 */
stClientData ConvertLineDataToRecord(string Line, string Seperator = "#//#") {

    stClientData ClientData;
    vector <string> vClient;
    vClient = SplitString(Line, Seperator);

    ClientData.AccountNumber = vClient[0];
    ClientData.PinCode = vClient[1];
    ClientData.FullName = vClient[2];
    ClientData.PhoneNumber = vClient[3];
    ClientData.AccountBalance = stod(vClient[4]);

    return ClientData;
}

/**
 * @brief Prints the details of a client record.
 *
 * @param ClientData The structured client data to display.
 */
void PrintClientData(stClientData ClientData) {
    cout << "\n\nThe following is the extracted client record: \n";

    cout << "Account Number  : " << ClientData.AccountNumber << endl;
    cout << "PinCode         : " << ClientData.PinCode << endl;
    cout << "Name            : " << ClientData.FullName << endl;
    cout << "Phone           : " << ClientData.PhoneNumber << endl;
    cout << "Account Balance : " << ClientData.AccountBalance << endl;
}

int main() {

	string sLineRecord = "A150#//#1234#//#Madi Abdelheq#//#0770791660#//#5270.0000";
	cout << "Line Record is: \n" << sLineRecord << endl;

	stClientData ClientData = ConvertLineDataToRecord(sLineRecord);

    PrintClientData(ClientData);

	return 0;
}