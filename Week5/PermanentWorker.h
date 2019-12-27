#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class PermanentWorker : public Employee {
	int salary;
public:
	PermanentWorker(string name, int salary) : Employee(name), salary(salary) {}
	virtual int getPay() {
		return salary;
	}
	void ShowInfo() {
		PrintName();
		cout << salary << endl;
	}
};