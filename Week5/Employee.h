#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee {
	string name;
public:
	Employee(string name) :name(name){

	}
	void PrintName() {
		cout << name << endl;
	}
	virtual void ShowInfo() = 0;
	virtual int getPay() = 0;
};

