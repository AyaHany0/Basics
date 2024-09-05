#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <fstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"
class FilesHelper {


    //**Note: Creating all files in the FilesHelper class is a better approach to 
    // encapsulate file management functionality in a seperate class.

    //private static method takes a file name as input to create all files we need.
    // by calling it in the public FileHelper class 

    static void createFile(const string& file_name) {
        ofstream file(file_name);
        if (file.is_open()) {
            cout << file_name << " is created successfully. \n";
            file.close();
        }
        else {
            cout << file_name << "Can't be created! \n";
        }
    }


public:

    // public static method will be called to create all files we needed.
    //files we need is :
    //Clients: to save all Clients data.
    //Employees: to save all Employee data.
    //Admins: to save all Admins data.
    //ClientsLastId: to save the last id of the clients file.
    //EmployeesLastId: to save the last id of the employees file.
    //AdminsLastId: to save the last id of the admins file.

    static void createFiles() {
        createFile("Clients.txt");
        createFile("Employees.txt");
        createFile("Admins.txt");
        createFile("ClientsLastId.txt");
        createFile("EmployeesLastId.txt");
        createFile("AdminsLastId.txt");
    }
    
    //Static method for all files to save the last id for all files in its files.

    static void saveLast(const string& file_name, int last_id) {
        ofstream file(file_name);
        if (file.is_open()) {
            file << last_id;
            file.close();
            cout << "Last ID saved successfully to file: " << file_name << endl;
        }
        else {
            cout << file_name << "Can't be created!" << endl;
        }
    }

    //Static method for all files to get the last id for all files from its files.

    static int getLast(const string& fileName) {
        ifstream file(fileName);
        int id;
        if (file.is_open()) {
            file >> id;
            file.close();
            return id;
        }
        else {
            cout << "Unable to open file: " << fileName << endl;
            return 0;
        }
    }

    //template method to save object to its file

    static void saveClient(Client& c) {

        int id = c.get_id();
        fstream file;
        file.open("Clients.txt", ios::app);
        file << c.get_name() << '*' <<  c.get_id()<< '*' << c.get_password() << '*' << c.get_balance() << "\n";
        file.close();
        saveLast("ClientLastId.txt", id );
    }
    static void saveEmployee(string fileName, string lastIdFile, Employee& e) {
        int id = e.get_id();
        fstream file;
        file.open(fileName, ios::app);
        file << e.get_name() << '*' << e.get_id( )<< '*' << e.get_password() << '*' << e.get_salary() << "\n";
        file.close();
        saveLast(lastIdFile, id );
    }
    static void getClients() {
        string line;
        ifstream file;
        file.open("Clients.txt");
        while (getline(file, line)) {
            Client c = Parser::parseToClient(line);
            allClients.push_back(c);
        }
        file.close();
    }
    static void getEmployees() {
        string line;
        ifstream file;
        file.open("Employees.txt");
        while (getline(file, line)) {
            Employee e = Parser::parseToEmployee(line);
            allEmployees.push_back(e);
        }
        file.close();
    }
    static void getAdmins() {
        string line;
        ifstream file;
        file.open("Admins.txt");
        while (getline(file, line)) {
            Admin a = Parser::parseToAdmin(line);
            allAdmins.push_back(a);
        }
        file.close();
    }



    static void clearFile(string file_name, string lastIdFile) {
        fstream file_1, file_2;
        file_1.open(file_name, ios::out, ios::trunc);
        file_1.close();
        file_2.open(lastIdFile, ios::out);
        file_2 << 0;
        file_2.close();
    }

};