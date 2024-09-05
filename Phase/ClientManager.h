#pragma once
#include<iostream>
#include"Client.h"
#include"FileManager.h"
using namespace std;
class ClientManager
{
public:
	static void printClientMenu() {
		cout << "\n Dear Customer, Welcome. \n \n";
		cout << "~ Your Menu: \n \n"
			<< "1-Deposit \t \t \t \t " << "2-Withdraw \n"
			<< "3-Transfer to \t \t \t \t " << "4-Check balance\n"
			<< "5-Print your info \t \t \t " << "6-Log out\n";
	}
	static void updatePassword(Person* person) {
		string newPassword;
		cout << "Enter new password: ";
		cin >> newPassword;
		person->set_password(newPassword);
		cout << "Password updated successfully!" << endl;
	}
	static Client* login(int id, string password) {

		Client* client = FileManager::findClientById(id);
		if (client != nullptr && client->get_password() == password) {
			return client;
			cout << "Log in successful! \n";
			
		}
		else {
			cout << "Invalid id or password. Please, try again." << endl;
			return nullptr;
		}
	}
	static bool clientOptions(Client* client) {
		
		printClientMenu();
		bool continueOperation = true;
		int choice;

		while (continueOperation)
		{
			cout << "\n \n - Enter your choice: \n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "======== Deposit:\n \n ";
				double despositAmount;
				cout << "Enter amount to deposit: \n";
				cin >> despositAmount;
				client->deposit(despositAmount);
				break;
			case 2:
			{
				cout << "======== Withdraw: \n";
				double withdrawAmount;
				cout << "Enter amount to withdraw: \n";
				cin >> withdrawAmount;
				client->withdraw(withdrawAmount);
				break;
			case 3:
				cout << "======= Transfer to: \n";
				double transferAmount;
				int recipientId;
				cout << "Enter amount to transfer: \n";
				cin >> transferAmount;
				cout << "Enter recipient's ID: \n";
				cin >> recipientId;
				Client* recipient = FileManager::findClientById(recipientId);
				if (recipient != NULL) {
					client->transferTo(transferAmount, *recipient);

				}
				else {
					cout << "Error: Can't find the repicient!" << endl;
				}

				break;
			}
			case 4:
				cout << "====== Check balance: \n";
				client->check_balance();
				break;
			case 5:
				cout << "===== Print your info: \n ";
				client->display_info();
				break;
			case 6:
				cout << "===== Log out: \n ";
				cout << "Logging out...." << endl;
				continueOperation = false;
				break;

			default:
				cout << "Invalid choice. Please try again.\n";
				break;
			}
			if (continueOperation) {
				char continueChoice;
				cout << "Do you want to perform another operation? (Y, N): ";
				cin >> continueChoice;
				if (toupper(continueChoice) != 'Y') {
					cout << "Logging out..." << endl;
					break;
				}
			}


		}
		return false;
	}
};