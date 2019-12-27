#include "AccountHandler.h"
#include "Account.h"
#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

using namespace std;

void AccountHandler::ShowMenu() const{
	cout << "1. ���� ����" << endl;
	cout << "2. ���� �Ա�" << endl;
	cout << "3. ���� ���" << endl;
	cout << "4. ���� ����" << endl;
	cout << "5. ����" << endl;
}
void AccountHandler::MakeAccount() {
	cout << "���� ������ �����Ͻÿ�" << endl;
	cout << "1. �븻 ����, 2. �ſ� ����" << endl;
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

	cout << "[�Ϲ� ���� ����]" << endl;
	cout << "���¹�ȣ : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������ : "; cin >> interRate;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);

}
void AccountHandler::MakeCreditAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ� ���� ����]" << endl;
	cout << "���¹�ȣ : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������ : "; cin >> interRate;
	cout << "�ſ��� : "; cin >> creditLevel;

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
	cout << "[�Ա�]" << endl;
	cout << "���¹�ȣ : "; cin >> id;
	cout << "�Ա� �ݾ� : "; cin >> money;

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
	cout << "���" << endl;
	cout << "���¹�ȣ"; cin >> id;
	cout << "��� �ݾ�"; cin >> money;

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