#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include"Admin.h"
#include"AdminManager.h"
#include"Client.h"
#include"ClientManager.h"
#include"DataSourceInterface.h"
#include"Employee.h"
#include"EmployeeManager.h"
#include"FileManager.h"
#include"FilesHelper.h"
#include"Parser.h"
#include"Person.h"
#include"Validation.h"
#include"Screen.h"




using namespace std;

int main() {

	Admin a("Mostafa Madian", 5000, "12345678910", 50000);
	allAdmins.push_back(a);

	Employee e1("Aya Hany", 1000, "12345678910", 10000);
	
	a.addEmployeeByAdmin(e1);
	Employee e2("Manar Hassan", 1001, "12345678910", 12000);
	
	a.addEmployeeByAdmin(e2);
	Employee e3("Duha Mohamed", 1002, "12345678910", 13000);
	
	a.addEmployeeByAdmin(e3);
	Employee e4("Hager yousry", 1003, "12345678910", 14000);
	
	a.addEmployeeByAdmin(e4);
	Employee e5("Aya Essam", 1004, "12345678910", 15000);
	
	a.addEmployeeByAdmin(e5);

	Client c1("Aya Hany", 2000, "12345678910", 10000);
	
	e1.addClient(c1);
	Client c2("Manar Hassan", 2001, "12345678910", 12000);
	
	e1.addClient(c2);
	Client c3("Duha Mohamed", 2002, "12345678910", 13000);
	
	e1.addClient(c3);
	Client c4("Hager yousry", 2003, "12345678910", 14000);
	
	e1.addClient(c4);

	Client c5("Aya Essam", 2004, "12345678910", 15000);
	
	e1.addClient(c5);

	 

	Screen::runApp();

	
}