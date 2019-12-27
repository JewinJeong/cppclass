#pragma once
#include <iostream>
#include <string>
#include "SalesWorker.h"

using namespace std;

enum{RISK_A = 1, RISK_B, RISK_C};

class ForeinSalesWorker : public SalesWorker {
	int riskLevel;
public:
	ForeinSalesWorker(string name, int salary, double bonusRatio, int riskLevel)
		: SalesWorker(name, salary, bonusRatio), riskLevel(riskLevel) {}
	int GetRiskPay() {
		int riskpay = SalesWorker::getPay();
		if (riskLevel == RISK_A) {
			riskpay *= 0.3;
		}
		else if(riskLevel == RISK_B){
			riskpay *= 0.2;
		}
		else {
			riskpay *= 0.1;
		}

		return riskpay;
	}
	virtual int getPay() {
		int pay = SalesWorker::getPay();
		return pay + GetRiskPay();
	}
	void ShowInfo() {
		int pay = SalesWorker::getPay();
		SalesWorker::PrintName();
		cout << pay << endl;
		cout << GetRiskPay() << endl;
		cout << pay + GetRiskPay() << endl;
	}
};
