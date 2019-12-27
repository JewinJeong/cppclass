#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

Account::Account(int ID, int money, char* name) : accID(ID), balance(money)
{
	cusName = new char[strlen(name+1)];
	strcpy(cusName, name);
}
Account::Account(const Account& account) : accID(account.accID), balance(account.balance) {
	cusName = new char[strlen(account.cusName)];
	strcpy(cusName, account.cusName);
}
int Account::getAccID() const {
	return accID;
}
void Account::Deposit(int money) {
	balance += money;
}
int Account::Withdraw(int money) {
	if (balance < money) {
		return 0;
	}
	else {
		balance -= money;
		return balance;
	}
}
void Account::ShowAccInfo() const {
	cout << "°èÁÂ¹øÈ£ : " << accID << endl;
	cout << "ÀÜ¾× :	" << balance << endl;
	cout << "°í°´ÀÌ¸§ : " << cusName << endl;
}
Account::~Account() {
	delete []cusName;
}

