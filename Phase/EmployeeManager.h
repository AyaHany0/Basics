#pragma once
#include<iostream>
#include"FileManager.h"
#include"Employee.h"
#include"ClientManager.h"
using namespace std;
class EmployeeManager
{
public:

	static void printEmployeeMenu() {
		cout << "Dear Employee, Welcome. \n \n";
		cout << "~ Your Menu: \n \n"
			<< "1-Add Client   \t \t \t \t\t " << "2-Search for Client \n"
			<< "3-List Clients  \t \t \t \t " << "4-Edit Client\n"
			<< "5-Print your info\t \t \t \t " << "6-Log out\n";

	}
	static void newClient(Employee* employee) {
		FileManager fm;
		string name, password;
		int id;
		double balance;
		cout << "Enter client name:\n ";
		cin >> name;
		cout << "Enter client id:\n";
		cin >> id;
		cout << "Enter client password:\n";
		cin >> password;
		cout << "Enter client balance:\n";
		cin >> balance;
		Client newClient(name,id, password, balance);

		employee->addClient(newClient);
		fm.addClient(newClient);
	}

	static void listAllClients(Employee* employee) {
		employee->listClients();
	}

	static void searchForClient(Employee* employee) {
		int client_id;
		cout << "Enter the ID of the client you want to search for:  ";
		cin >> client_id;
		Client* client = employee->searchClient(client_id);
		if (client != nullptr) {
			cout << "Client is found:\n";
			client->display_info();
		}
		else {
			cout << "Client with ID " << client_id << " not found!" << endl;
		}
	}


	static void editClientInfo(Employee* employee) {
		int client_id;
		cout << "Enter the ID of the client you want to edit: ";
		cin >> client_id;


		Client* client = employee->searchClient(client_id);
		if (client != nullptr) {
			std::string new_name, new_password;
			double new_balance;


			cout << "Enter new name for the client: ";
			cin >> new_name;
			cout << "Enter new password for the client: ";
			cin >> new_password;
			cout << "Enter new balance for the client: ";
			cin >> new_balance;


			employee->editClient(client_id, new_name, new_password, new_balance);
			cout << "Client information updated successfully." << endl;
		}
		else {
			cout << "Client with ID " << client_id << " not found!" << endl;
		}
	}


	static Employee* logIn(int id, string password) {

		Employee* employee = FileManager::findEmployeeById(id);
		if (employee != nullptr) {

			if (employee->get_password() == password) {
				cout << "Logging in..... \n";
				return employee;
				
			}
			else {
				cout << "Incorrect password. Please try again." << endl;
			}
		}
		else {
			cout << "Employee with ID " << id << " not found." << endl;
		}
		return nullptr;
	}

	static bool employeeOptions(Employee* employee) {

		int choice;
		bool continueOperation = true;
		printEmployeeMenu();
		while (continueOperation) {
			cout << "\n \n - Enter your choice: \n";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Add Client: \n";
				newClient(employee);
				break;
			case 2:
				cout << "Search for Client: \n";
				searchForClient(employee);
				break;
			case 3:
				cout << "List All Clients: \n";
				listAllClients(employee);
				break;
			case 4:
				cout << "Edit Client info: \n";
				editClientInfo(employee);
				break;
			case 5:
				cout << "Print my info: \n";
				employee->display_info();
				break;
			case 6:
				cout << "Log out: \n";
				cout << "Logging out..." << endl;
				continueOperation = false;
				break;

			default:
				cout << "Invalid choice. Please try again." << endl;
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