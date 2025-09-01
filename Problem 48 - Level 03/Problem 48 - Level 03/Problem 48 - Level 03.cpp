/**
 * @brief Problem 48 - Level 03: Show All Clients from File
 *
 * This program reads all client records stored in a file,
 * converts each line into a structured client record,
 * and displays them in a formatted table.
 */

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
 * @brief Prints a single client record in a formatted row.
 * @param ClientData The client record to print.
 */
void PrintClientData(stClientData ClientData) {

	cout << "| " << left << setw(15) << ClientData.AccountNumber;
	cout << "| " << left << setw(10) << ClientData.PinCode;
	cout << "| " << left << setw(40) << ClientData.FullName;
	cout << "| " << left << setw(12) << ClientData.PhoneNumber;
	cout << "| " << left << setw(12) << ClientData.AccountBalance;
}

/**
 * @brief Prints all clients' data in a formatted table.
 * @param vClientDataFile A vector containing all client records.
 */
void PrintAllClientsData(vector <stClientData> vClientDataFile) {
	cout << "\n\t\t\t\t\tClient List (" << vClientDataFile.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (stClientData& Client : vClientDataFile) {
		PrintClientData(Client);
		cout << endl;
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

int main() {
	
	vector <stClientData> vClientDataFile = LoadClientsDataFromFile("ClientDataFile.txt");

	PrintAllClientsData(vClientDataFile);

	return 0;
}