#include "Account.h"
#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"

NormalAccount::NormalAccount(int ID, int money, char* name, int rate) : Account(ID, money, name), interRate(rate){
}
void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
	Account::Deposit(money*(interRate / 100.0));
}
