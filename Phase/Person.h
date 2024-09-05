#pragma once
#include <iostream>
using namespace std;
#include "Validation.h"

class Person
{
protected:
	string name, password;
	 int id;

public:

	//Constructors pramatarized (the default one here doesd't make sense as noone doesn't have name and id )
	Person(string name, int id, string password) :
		id(id) {
		set_name(name);
		set_password(password);
	};


	//Setters:
	void set_name(string name) {
		if (Validation::isAlphabitic(name) && Validation::isValidSize(name, 5, 20)) {
			Person::name = name;
			return;
		}
		Person::name = "Invalid.";
		cout << "Invalid input. Please enter a name with length between 5 and 20 characters and  containing only alphabetic characters.\n";

	}
	void set_id(int id) {
		Person::id = id;
	}
	void set_password(string password) {
		if (Validation::isValidSize(password, 8, 20)) {
			Person::password = password;
			return;
		}
		Person::password = "Invalid.";
		cout << "Invalid input. Please enter a name with length between 8 and 20 characters.\n";
	}
	//Getter:

	string get_name() {
		return name;
	}
	int get_id() {
		return id;
	}
	string get_password() {
		return password;
	}
	//
	//Methods:
	virtual void display_info() = 0;

};

