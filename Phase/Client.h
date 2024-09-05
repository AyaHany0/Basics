#pragma once
#include <iostream>
#include<sstream>
#include<vector>
using namespace std;
#include "Person.h"
#include "Validation.h"
class Client : public Person {
private:
	double  balance;
public:
	// Constructor

	Client(string name, int id, string password, double balance) :
		Person(name, id, password) {
		set_balance(balance);
	};
	// Setter functions
	void set_balance(double balance) {
		if (Validation::isValidSalaryBalance(balance, 1500)) {
			this->balance = balance;
			return;
		}
		this->balance = 1500;
	}
	// Getter functions

	double  get_balance() const {
		return balance;
	}

	// Other functions
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
		}
		else {
			cout << "Error: Deposit amount must be positive." << endl;
		}
	}

	void withdraw(double amount) {
		if (amount > 0) {
			if (balance >= amount) {
				balance -= amount;
				cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
			}
			else {
				cout << "Error: Insufficient funds." << endl;
			}
		}
		else {
			cout << "Error: Withdrawal amount must be positive." << endl;
		}
	}

	void transferTo(double amount, Client& client) {
		if (amount > 0 && balance >= amount) {
			withdraw(amount);
			client.deposit(amount);
		}
		else {
			cout << "Error: Insufficient funds or invalid amount for transfer." << endl;
		}
	}

	void check_balance() const {
		cout << "Current balance for client " << name << ": $" << balance << endl;
	}

	// Display function
	void display_info() {
		cout << "Client Details:" << endl
			<< "ID: " << id << endl
			<< "Name: " << name << endl
			<< "Balance: $" << balance << endl;
	}



};

static vector<Client> allClients;
static vector<Client>::iterator clientIt;
