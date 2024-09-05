#pragma once
#include<sstream>
#include<vector>
#include "Person.h"
#include"Employee.h"
#include "Validation.h"
class Admin : public Employee {

public:

	Admin(string name, int id, string password, double salary)
		: Employee(name, id, password, salary) {
	}

	//Method:
	void display_info() {
		cout << "Admin info: \n"
			<< "Name: " << name << endl
			<< "ID:" << id << endl
			<< "Password: " << password << endl
			<< "Salary: " << salary << endl;
	}

	void addEmployeeByAdmin(Employee& employee) {
		allEmployees.push_back(employee);
		
	}
	Employee* searchEmployee(int id) {
		for (employeeIt = allEmployees.begin(); employeeIt != allEmployees.end(); employeeIt++) {
			if (employeeIt->get_id() == id) return employeeIt._Ptr;
		}
		return NULL;
	}
	void editEmployeeByAdmin(int id, string name, string password, double salary) {
		searchEmployee(id)->set_name(name);
		searchEmployee(id)->set_password(password);
		searchEmployee(id)->set_salary(salary);
	}
	void listEmployeeByAdmin() {
		for (employeeIt = allEmployees.begin(); employeeIt != allEmployees.end(); employeeIt++) {
			employeeIt->display_info();
			cout << endl << "--------------------\n";
		}
	}



};

static vector<Admin> allAdmins;
static vector<Admin>::iterator adminIt;