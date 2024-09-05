#pragma once
#include <iostream>
using namespace std;
class Validation
{
public:
	//Validation method to ensure that the string have only alphabitic letters.
	static bool isAlphabitic(string str) {
		for (int i = 0; i < str.size(); i++) {
			if (!(isalpha(str[i]) || str[i] == ' ')) {
				return false;
			}
		}
		return true;
	}

	//Validation method to ensure that the string have the same size requirement.
	static bool isValidSize(string str, int minsize, int maxsize) {

		return (str.size() >= minsize && str.size() <= maxsize);
	}

	//Validation method to ensure that the salary meets the requirement.

	static bool isValidSalaryBalance(double salaryBalance, double minSalaryBalance) {
		return (salaryBalance >= minSalaryBalance);
	}

};
