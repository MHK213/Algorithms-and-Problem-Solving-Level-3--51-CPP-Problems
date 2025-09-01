#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
 * @brief Reads client data from user input.
 * @return stClientData structure with user-provided values.
 */
stClientData ReadClientData(stClientData& ClientData) {

	cout << "Enter Account Number? ";
	getline(cin >> ws, ClientData.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, ClientData.PinCode);

	cout << "Enter Name? ";
	getline(cin, ClientData.FullName);

	cout << "Enter Phone? ";
	getline(cin, ClientData.PhoneNumber);

	cout << "Enter AccountBalance? ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

/**
 * @brief Converts a client record into a single string line with separators.
 * @param ClientData The client data to convert.
 * @param Separator The string used to separate fields.
 * @return A string representing the client record.
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
 * @brief Appends a client data line to a file.
 * @param Line The line of client data to write.
 * @param FileName The file name where the record will be saved.
 */
void AddClientDataLineToFile(string Line, string FileName) {

	fstream ClientDataFile;
	ClientDataFile.open(FileName, ios::out | ios::app);

	if (ClientDataFile.is_open()) {
		ClientDataFile << Line << endl;
		ClientDataFile.close();
	}
}

/**
 * @brief Reads client data from the user and adds it to the file.
 */
void AddNewClient() {
	stClientData ClientData;
	ReadClientData(ClientData);

	AddClientDataLineToFile(ConvertRecordToLine(ClientData, "#//#"), "ClientDataFile.txt");
}

/**
 * @brief Allows adding multiple clients interactively.
 *
 * Keeps asking the user to add new clients until they choose not to.
 */
void AddClient() {
	char AddMore = 'Y';

	do{
		system("cls");
		cout << "Adding New Client:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

int main() {

	AddClient();

	return 0;
}