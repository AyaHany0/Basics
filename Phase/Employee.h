#pragma once
#include<iostream>
#include<sstream>
#include <fstream>
#include<vector>
#include "Person.h"
#include "Validation.h"
#include"Client.h"

class Employee : public Person
{
protected:
	double salary;
public:
	//Constructor:
	Employee(string name, int id, string password, double salary) :
		Person(name, id, password) {
		set_salary(salary);
	};

	//Setters: 
	void set_salary(double salary) {
		if (Validation::isValidSalaryBalance(salary, 5000)) {
			Employee::salary = salary;
			return;
		}
		else {
			cout << "Invalid input.The minimum salary to enter is 5000.\n";
			Employee::salary = 5000;
		}
	}
	//Getters: 
	double get_salary() {
		return salary;
	}
	//Methods: 
	void display_info() {
		cout << "Employee info: \n"
			<< "Name: " << name << endl
			<< "ID:" << id << endl
			<< "Password: " << password << endl
			<< "Salary: " << salary << endl;
	}

	void addClient(Client& client) {
		allClients.push_back(client);
	}

	Client* searchClient(int id) {
		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
			if (clientIt->get_id() == id) {
				return clientIt._Ptr;
			}

		}
		return NULL;
	}

	

	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->set_name(name);
		searchClient(id)->set_password(password);
		searchClient(id)->set_balance(balance);
	}

	void listClients() {
		if (allClients.empty()) {
			cout << "No clients found." << endl;
			return;
		}
		cout << "All Clients:\n";
		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
			clientIt->display_info();
			cout << endl << "-------------------------" << endl;
		}
	}

};

static vector<Employee> allEmployees;
static vector<Employee>::iterator employeeIt;
