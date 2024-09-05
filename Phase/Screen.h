#pragma once
#include <iostream>
#include <windows.h>  
#include<stdlib.h>
#include "screen.h"
#include "EmployeeManager.h"
#include"Employee.h"
#include "ClientManager.h"
#include "AdminManager.h"
#include <MMSystem.h>
#include "resource.h"

using namespace std;

#pragma comment(lib,"winmm.lib")



using namespace std;
class Screen
{
public:
    static void bankName() {

        system("Color DE");
        cout << "\t\t\t\t\t\t\tMantora Bank" << endl;
    }
    static void welcome() {
        cout << "\t \t \t \t \t \t    welcome to our project" << endl;
    }
    static void playMusic() {
        PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
    }

    static void loginOptions() {
        cout << "1. Login as Client" << endl;
        cout << "2. Login as Employee" << endl;
        cout << "3. Login as Admin" << endl;
        cout << "4. Exit" << endl;
    }
    static int loginAs() {
        int choice;
        cout << "Choose an option: ";
        cin >> choice;
        return choice;
    }

    static void invalid(int c) {
        cout << "Invalid input. Please try again." << endl;
    }

    static void logout() {
        cout << "Logged out successfully." << endl;
    }

    static void loginScreen(int c) {
        switch (c) {
        case 1:
            cout << "Client Login" << endl;
            break;
        case 2:
            cout << "Employee Login" << endl;
            break;
        case 3:
            cout << "Admin Login" << endl;
            break;
        }
    }

    static void runApp() {
        int id;
        string password;
        bankName();
        welcome();
        playMusic();
        while (true) {
            loginOptions();
            int choice = loginAs();
            if (choice == 1) {
                cout << "Enter your ID: ";
                cin >> id;
                cout << "Enter your password: ";
                cin >> password;
                Client* loggedInClient = ClientManager::login(id, password); 
                bool continueOperation = ClientManager::clientOptions(loggedInClient); 
                    break;
            }
            else if (choice == 2) {
                cout << "Enter your ID: ";
                cin >> id;
                cout << "Enter your password: ";
                cin >> password;
                Employee* loggedInEmployee = EmployeeManager::logIn(id, password);
                bool continueOperation = EmployeeManager::employeeOptions(loggedInEmployee); 
                    break;
            }
            else if (choice == 3) {
                cout << "Enter your ID: ";
                cin >> id;
                cout << "Enter your password: ";
                cin >> password;
                Admin* loggedInAdmin = AdminManager::logIn(id, password);
                bool continueOperation = AdminManager::AdminOptions(loggedInAdmin);
                break;
            }
            else if (choice == 4) {
                logout();
                break;
            }
            else if (choice < 1 || choice > 3) {
                invalid(choice);
                continue;
            }
        }
    }
};