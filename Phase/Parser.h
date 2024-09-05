#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
class Parser
{

public:

	static Client parseToClient(string& line) {
		vector<string> tokens = split(line);
		string name = tokens[0];
		int id = stoi(tokens[1]);
		string password = tokens[2];
		double balance = stod(tokens[3]);
		return Client(name, id ,password, balance);
	}

	static Employee parseToEmployee(string& line) {
		vector<string> tokens = split(line);
		string name = tokens[0];
		int id = stoi(tokens[1]);
		string password = tokens[2];
		double salary = stod(tokens[3]);
		return Employee(name, id, password, salary);
	}
	static Admin parseToAdmin(string& line) {
		vector<string> tokens = split(line);
		string name = tokens[0];
		int id = stoi(tokens[1]);
		string password = tokens[2];
		double salary = stod(tokens[3]);
		return Admin(name, id, password, salary);
	}


private:


	//Split function to split the string into the attribute
	static vector<string> split(const string& line, char delimiter = '*') {
		vector<string> tokens;
		string token;
		istringstream tokenStream(line);
		while (getline(tokenStream, token, delimiter)) {
			tokens.push_back(token);
		}
		return tokens;
	}
};