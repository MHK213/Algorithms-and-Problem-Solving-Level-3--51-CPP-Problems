#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// File name where client records are stored
string ClientsFileName = "ClientDataFile.txt";

/**
 * @struct stClientData
 * @brief Structure that holds all client-related data.
 *
 * Each client record contains account details such as:
 * - Account Number
 * - Pin Code
 * - Full Name
 * - Phone Number
 * - Account Balance
 */
struct stClientData {
	string AccountNumber, PinCode, FullName, PhoneNumber;
	double AccountBalance;
};

/**
 * @brief Reads new client data from user input (used when updating).
 * @param AccountNumber The account number of the client being updated.
 * @return A filled stClientData structure with updated values.
 */
stClientData UpdateClientRecord(string AccountNumber) {

	stClientData ClientData;

	ClientData.AccountNumber = AccountNumber;

	cout << "\nEnter PinCode? ";
	getline(cin >> ws, ClientData.PinCode);

	cout << "Enter Name? ";
	getline(cin, ClientData.FullName);

	cout << "Enter Phone? ";
	getline(cin, ClientData.PhoneNumber);

	cout << "Enter AccountBalance? ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

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
 * @brief Converts a structured client record into a string for file storage.
 * @param ClientData The client record to convert.
 * @param Seprator The delimiter string to separate fields.
 * @return A formatted string representing the client record.
 */
string ConvertRecordToLine(stClientData& ClientData, string Seprator) {

	string stClientRecord = "";

	stClientRecord += ClientData.AccountNumber + Seprator;
	stClientRecord += ClientData.PinCode + Seprator;
	stClientRecord += ClientData.FullName + Seprator;
	stClientRecord += ClientData.PhoneNumber + Seprator;
	stClientRecord += to_string(ClientData.AccountBalance);

	return stClientRecord;
}

/**
 * @brief Finds a client by account number from a vector of clients.
 * @param AccountNumber The account number to search for.
 * @param vClients The vector of client records.
 * @param Client Output parameter that will hold the client record if found.
 * @return true if client is found, false otherwise.
 */
bool FindClientByAccountNumber(string AccountNumber, vector <stClientData> vClients, stClientData& Client) {

	for (stClientData& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}

	return false;
}

/**
 * @brief Saves all clients back to the file after updates.
 * @param FileName The file name where client data will be saved.
 * @param vClients Vector containing updated client records.
 * @return The updated vector of clients.
 */
vector <stClientData> SaveClientDataToFile(string FileName, vector <stClientData> vClients) {
	fstream MyFile;

	MyFile.open(FileName, ios::out);
	string DataLine;
	if (MyFile.is_open()) {

		for (stClientData& C : vClients) {
				DataLine = ConvertRecordToLine(C, "#//#");
				MyFile << DataLine << endl;
		}

		MyFile.close();
	}

	return vClients;
}

/**
 * @brief Updates a client by their account number.
 * @param AccountNumber The account number of the client to update.
 * @param vClients The vector of clients to modify.
 * @return true if client was updated, false if not found.
 */
bool UpdateClientByAccountNumber(string AccountNumber, vector <stClientData>& vClients) {

	stClientData Client;
	char Answer = 'N';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		PrintClientData(Client);

		cout << "\nAre you sure you want to Update this client? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') {
			for (stClientData& C : vClients) {
				if (C.AccountNumber == AccountNumber) {
					C = UpdateClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully" << endl;
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
		return false;
	}
}

/**
 * @brief Entry point. Loads clients, asks for account number, updates record.
 */
int main() {

	vector <stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClients);

	return 0;
}