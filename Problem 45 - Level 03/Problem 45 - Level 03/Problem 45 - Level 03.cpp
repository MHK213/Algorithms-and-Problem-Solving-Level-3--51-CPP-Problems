#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClientData {
	string AccountNumber, PinCode, FullName, PhoneNumber;
	double AccountBalance;
};

/**
 * @brief Reads client data from user input.
 * @return stClientData structure with user-provided values.
 */
stClientData ReadClientData(stClientData& ClientData) {
	
	cout << "Please Enter Client Data:\n\n";

	cout << "Enter Account Number? ";
	getline(cin, ClientData.AccountNumber);

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

int main() {

	stClientData ClientData;
	ReadClientData(ClientData);

	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(ClientData, "#//#") << endl;

	return 0;
}