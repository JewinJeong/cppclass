#include <iostream>
#include "Employee.h"
#include "ForeignWorker.h"
#include "PermanentWorker.h"
#include "SalesWorker.h"
#include "TemporaryWorker.h"
#include "EmployeeHandler.h"
#include <string>
using namespace std;

int main() {
	EmployeeHandler handler;

	PermanentWorker * per1 = new PermanentWorker("Kim", 1000);
	handler.AddEmployee(per1);
	PermanentWorker * per2 = new PermanentWorker("Lee", 1500);
	handler.AddEmployee(per2);

	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	ForeinSalesWorker * fseller = new ForeinSalesWorker("Park", 1000, 0.1, RISK_B);
	fseller->AddSalesResult(7000);
	handler.AddEmployee(fseller);



	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
	system("pause");
	return 0;
}