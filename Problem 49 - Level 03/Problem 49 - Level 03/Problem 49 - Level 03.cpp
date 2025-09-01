#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * @struct stClientData
 * @brief Structure that holds all client-related data.
 */
struct stClientData {
	string AccountNumber, PinCode, FullName, PhoneNumber;
	double AccountBalance;
};

/**
 * @brief Reads an account number from user input.
 * @return The account number entered by the user.
 */
string ReadClientAccountNumber() {
	string AccountNumber;
	cout << "Please Enter Account Number? ";
	cin >> AccountNumber;

	return AccountNumber;
}

/**
 * @brief Splits a string into a vector of substrings based on a delimiter.
 * @param Text The input string.
 * @param delim The delimiter string.
 * @return A vector of substrings.
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
 * @brief Converts a line of text into a structured client record.
 * @param Line The input line containing client data.
 * @param Seperator The delimiter used in the line (default "#//#").
 * @return A stClientData structure.
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
 * @brief Loads all clients' data from a given file.
 * @param FileName The name of the file containing client data.
 * @return A vector of stClientData records.
 */
vector <stClientData> LoadClientsDataFromFile(string FileName) {

	vector <stClientData> vFileContent;
	fstream MyFile;

	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		stClientData Client;

		while (getline(MyFile, Line)) {
			Client = ConvertLineDataToRecord(Line);
			vFileContent.push_back(Client);
		}

		MyFile.close();
	}

	return vFileContent;
}

/**
 * @brief Prints a single client's information to the console.
 * @param ClientData The client record to print.
 */
void PrintClientData(stClientData ClientData) {

	cout << "\n\nThe Following are the client details: \n\n";
	cout << "Account Number  : " << ClientData.AccountNumber << endl;
	cout << "PinCode         : " << ClientData.PinCode << endl;
	cout << "Name            : " << ClientData.FullName << endl;
	cout << "Phone           : " << ClientData.PhoneNumber << endl;
	cout << "Account Balance : " << ClientData.AccountBalance << endl;
}

/**
 * @brief Searches for a client in the file by account number.
 * @param AccountNumber The account number to search for.
 * @param Client Reference where the found client data will be stored.
 * @return True if the client is found, false otherwise.
 */
bool FindClientByAccountNumber(string AccountNumber, stClientData& Client) {
	vector <stClientData> vClientDataFile = LoadClientsDataFromFile("ClientDataFile.txt");

	for (stClientData& C : vClientDataFile) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}

	return false;
}

int main() {

	stClientData Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
		PrintClientData(Client);
	else
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";

	return 0;
}