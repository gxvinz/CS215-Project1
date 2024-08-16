//------------------------------------------------------------------------------------
//                          Project 1- ATM
//                        Joseph Gavin Crain
//                             2/13/2020
//                        CS215 Section 402
// This program simulates an ATM machine, giving the user the 
// option to do things such as withdrawal, deposit, check balance, etc
//-------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	// setting up atm to run continuously 
	int a = 2;
	while (a > 1) {
		// beginning of transaction 
		cout << "+-------------------------+\n";
		cout << "| Joseph Crain Bank, Inc. |\n";
		cout << "|        CS215-402        |\n";
		cout << "+-------------------------+\n";

		cout << fixed << setprecision(2);

		string accountNum;
		double accountBal;

		cout << "Enter account number:  ";
		cin >> accountNum;
		
		// shutdown code
		if (accountNum == "shutdown") {
			cout << "Shutting down...bye!" << endl;
			system("pause");
			return 0;
		}

		cout << "Enter account balance: ";
		cin >> accountBal;
		
		cout << endl;
		// print menu
		string option;
		cout << "B - Balance Inquiry" << endl;
		cout << "D - Deposit" << endl;
		cout << "W - Withdrawal" << endl;
		
		// setting it to run until the correct input 
		int c = 2;
		while (c > 1) {
			c = 0;
			// getting user selection
			cout << "Choose an option: ";
			cin >> option;
			cout << endl;
			if (option == "B") {
				// balance inquiry
				cout << "+-------------------------+\n";
				cout << "| Joseph Crain Bank, Inc. |\n";
				cout << "+-------------------------+\n";
				cout << "Account: " << accountNum << endl;
				cout << "Balance: $ " << accountBal << endl;
				cout << endl;
			}
			else if (option == "D") {
				// deposit
				float deposit;
				double newBal;
				cout << "Enter deposit amount: ";
				cin >> deposit;
				newBal = accountBal + deposit;
				cout << "+-------------------------+\n";
				cout << "| Joseph Crain Bank, Inc. |\n";
				cout << "+-------------------------+\n";
				cout << "Account:  " << accountNum << endl;
				cout << "Prev Bal: $ " << accountBal << endl;
				cout << "Deposit:  $ " << deposit << endl;
				cout << "New Bal:  $ " << newBal << endl;
				cout << endl;
			}
			else if (option == "W") {
				// withdrawal
				int b = 1;
				float withdraw;
				double withdrawBal;
				// making withdrawal restart if too much is requested
				while (b == 1) {
					b = 0;
					cout << "Enter withdrawal amount: ";
					cin >> withdraw;

					if (withdraw > accountBal) {
						cout << "Insufficient Funds. Current Balance is $ " << accountBal;
						b = 1;
						cout << endl;
					}

				}
				cout << "+-------------------------+\n";
				cout << "| Joseph Crain Bank, Inc. |\n";
				cout << "+-------------------------+\n";
				withdrawBal = accountBal - withdraw;
				cout << "Account:   " << accountNum << endl;
				cout << "Prev Bal:  $ " << accountBal << endl;
				cout << "Withdrawn: $ " << withdraw << endl;
				cout << "New Bal:   $ " << withdrawBal << endl;
				cout << endl;
			}
			else {
				// if wrong value is entered - sends back to top of while loop
				cout << '"' << option << '"' << " is an invalid option. Enter B, D or W." << endl;
				c = 2;
			}
		}
	}
	system("pause");
	return 0;
}