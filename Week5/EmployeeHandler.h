#pragma once
#include <iostream>
#include "Employee.h"

class EmployeeHandler {
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowInfo();

	}
	void ShowTotalSalary() const {
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->getPay();

		cout << "salary sum : " << sum << endl;
	}

	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};


