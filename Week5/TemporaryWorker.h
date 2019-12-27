#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class TemporaryWorker : public Employee {
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(string name, int pay) : Employee(name),payPerHour(pay), workTime(0) {

	}
	void AddWorkTime(int workTime) {
		this->workTime += workTime;
	}
	virtual int getPay() {
		return workTime * payPerHour;
	}
	void ShowInfo() {
		Employee::PrintName();
		cout << "moeny : " << workTime * payPerHour << endl;

	}
};
