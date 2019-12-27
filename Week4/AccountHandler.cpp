#include "AccountHandler.h"
#include "Account.h"
#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

using namespace std;

void AccountHandler::ShowMenu() const{
	cout << "1. 계좌 개설" << endl;
	cout << "2. 계좌 입금" << endl;
	cout << "3. 계좌 출금" << endl;
	cout << "4. 계좌 정보" << endl;
	cout << "5. 종료" << endl;
}
void AccountHandler::MakeAccount() {
	cout << "계좌 종류를 선택하시오" << endl;
	cout << "1. 노말 계좌, 2. 신용 계좌" << endl;
	int input;
	cin >> input;
	if (input == 1) {
		MakeNormalAccount();
	}
	else if (input == 2) {
		MakeCreditAccount();
	}
	else {
	
	}
}
void AccountHandler::MakeNormalAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[일반 계좌 생성]" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << "이자율 : "; cin >> interRate;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);

}
void AccountHandler::MakeCreditAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용 계좌 생성]" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << "이자율 : "; cin >> interRate;
	cout << "신용등급 : "; cin >> creditLevel;

	switch (creditLevel) {
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
	}
}
void AccountHandler::DepositMoney() {
	int money;
	int id;
	cout << "[입금]" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "입금 금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "Deposit Completed" << endl;
			return;
		}
	}
	cout << "Invalid ID" << endl << endl;
}
void AccountHandler::WithdrawMoney() {
	int money;
	int id;
	cout << "출금" << endl;
	cout << "계좌번호"; cin >> id;
	cout << "출금 금액"; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "Not enough your Balance" << endl << endl;
				return;
			}
			cout << "Withdraw Completed" << endl << endl;
			return;
		}
	}
	cout << "Invalid ID" << endl << endl;
}
AccountHandler::AccountHandler() : accNum(0) {}
void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}