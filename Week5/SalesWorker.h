#pragma once

#include <iostream>
#include <string>
#include "PermanentWorker.h"
#include "Employee.h"
#include "TemporaryWorker.h"

using namespace std;

class SalesWorker : public PermanentWorker {
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(string name, int salay, double bonusRatio):PermanentWorker(name, salay), bonusRatio(bonusRatio), salesResult(0){}
	void AddSalesResult(int salesResult) {
		this->salesResult = this->salesResult + salesResult;
	}
	virtual int getPay() {
		return PermanentWorker::getPay() + salesResult * bonusRatio;
	}
	void ShowInfo() {
		Employee::PrintName();
		cout << PermanentWorker::getPay() + salesResult * bonusRatio << endl;
	}

};