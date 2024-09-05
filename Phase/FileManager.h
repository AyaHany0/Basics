#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:
	 void addClient(Client& client) {
		FilesHelper::saveClient(client);
	}
	 void addEmployee(Employee& employee) {
		FilesHelper::saveEmployee("Employees.txt", "EmployeeLastID.txt", employee);
	}
	  void addAdmin(Admin& admin) {
		FilesHelper::saveEmployee("Admins.txt", "AdminLastID.txt", admin);
	}
	void getAllClients() {
		FilesHelper::getClients();
	};
	void getAllEmployees() {
		FilesHelper::getEmployees();
	};
	void getAllAdmins() {
		FilesHelper::getAdmins();
	};
	void removeAllClients() {
		FilesHelper::clearFile("ClientData.txt", "ClientLastID.txt");
	}
	void removeAllEmployees() {
		FilesHelper::clearFile("EmployeeData.txt", "EmployeeLastID.txt");
	}
	void removeAllAdmins() {
		FilesHelper::clearFile("AdminData.txt", "AdminLastData.txt");
	}
	void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	void updateClient() {
		removeAllClients();
		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++)
		{
			addClient(*clientIt);
		}
	}
	void updateEmployee() {
		removeAllEmployees();
		for (employeeIt = allEmployees.begin(); employeeIt != allEmployees.end(); employeeIt++)
		{
			addEmployee(*employeeIt);
		}
	}
	void updateAdmin() {
		removeAllAdmins();
		for (adminIt = allAdmins.begin(); adminIt != allAdmins.end(); adminIt++)
		{
			addAdmin(*adminIt);
		}

	}
	static Client* findClientById(int id) {
		for (auto& client : allClients) {
			if (client.get_id() == id) {
				return &client;
			}
		}
		return nullptr;
	}
	static Employee* findEmployeeById(int id) {
		for (auto& employee : allEmployees) {
			if (employee.get_id() == id) {
				return &employee;
			}
		}
		return nullptr;
	}
	static Admin* findAdminById(int id) {
		for (auto& admin : allAdmins) {
			if (admin.get_id() == id) {
				return &admin;
			}
		}
		return nullptr;
	}
};