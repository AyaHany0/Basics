#pragma once
using namespace std;
#include <iostream>
#include "Admin.h"
#include "FileManager.h"
#include "Employee.h"
#include "EmployeeManager.h"



class AdminManager
{
public:
	static void printAdminMenu() {
		cout << "Dear Admin, Welcome. \n \n";
		cout << "~ Your Menu: \n \n"
			<< "1-Add Client   \t \t \t \t\t " << "2-Search for Client \n"
			<< "3-List Clients  \t \t \t \t " << "4-Edit Client\n"
			<<"5-Add Employee    \t \t \t \t " <<"6-Search for Employee\n"
			<<"7-List Employees  \t \t \t \t "<<"8-Edit Employee\n"
			<< "9-Print your info\t \t \t \t " << "10-Log out\n";

	}
	static void newEmployee(Admin* Admin) {
		FileManager fm;
		string name, password;
		int id;
		double salary;
		cout << "Enter Employee name:\n ";
		cin >> name;
		cout << "Enter Employee id:\n";
		cin >> id;
		cout << "Enter Employee password:\n";
		cin >> password;
		cout << "Enter Employee balance:\n";
		cin >> salary;
		Employee newEmployee(name, id, password, salary);

		Admin->addEmployeeByAdmin(newEmployee);
		fm.addEmployee(newEmployee);
	}

	static void listAllEmployees(Admin* admin) {
		admin->listEmployeeByAdmin();
	}

	static void searchForEmployee(Admin* Admin) {
		int employee_id;
		cout << "Enter the ID of the employee you want to search for:  ";
		cin >> employee_id;
		Employee* employee = Admin->searchEmployee(employee_id);
		if (employee != nullptr) {
			cout << "Employee is found:\n";
			employee->display_info();
		}
		else {
			cout << "Employee with ID " << employee_id << " not found!" << endl;
		}
	}

	static void editEmployeeInfo(Admin* admin) {
		int employee_id;
		cout << "Enter the ID of the client you want to edit: ";
		cin >> employee_id;
		
		Employee* employee = admin->searchEmployee(employee_id);
		if (employee != nullptr) {
			std::string new_name, new_password;
			double new_salary;


			cout << "Enter new name for the employee: ";
			cin >> new_name;
			cout << "Enter new password for the employee: ";
			cin >> new_password;
			cout << "Enter new balance for the employee: ";
			cin >> new_salary;


			admin->editEmployeeByAdmin(employee_id, new_name, new_password, new_salary);
			cout << "employee information updated successfully." << endl;
		}
		else {
			cout << "employee with ID " << employee_id << " not found!" << endl;
		}
	}


	static Admin* logIn(int id, string password) {

		Admin* Admin = FileManager::findAdminById(id);
		if (Admin != nullptr) {

			if (Admin->get_password() == password) {

				return Admin;
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
	static bool AdminOptions(Admin* Admin) {
		FileManager fm;
		int choice;
		bool continueOperation = true;
		printAdminMenu();
		while (continueOperation) {
			cout << "\n \n - Enter your choice: \n";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Add Client: \n";
				EmployeeManager::newClient(Admin);
				break;
			case 2:
				cout << "Search for Client: \n";
				EmployeeManager::searchForClient(Admin);
				break;
			case 3:
				cout << "List All Clients: \n";
				EmployeeManager::listAllClients(Admin);
				break;
			case 4:
				cout << "Edit Client info: \n";
				EmployeeManager::editClientInfo(Admin);
				break;
			case 5 :
				cout << "Add Employee: \n";
				newEmployee(Admin);
				break;
			case 6:
				cout << "Search for Employee: \n";
				searchForEmployee(Admin);
				break;
			case 7:
				cout << "List Employees:\n";
				listAllEmployees(Admin);
				break;
			case 8:
				cout << "Edit Employee: \n";
				editEmployeeInfo(Admin);
				break;
			
			case 9:
				cout << "Print my info: \n";
				Admin->display_info();
				break;
			case 10:
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
				cout << "Do you want to perform another operation? ( Y , N ): ";
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