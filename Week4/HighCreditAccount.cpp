#include "HighCreditAccount.h"
#include "NormalAccount.h"

HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int rate, int special)
	:NormalAccount(ID,money,name,rate), specialRate(special) {
	
}
void HighCreditAccount::Deposit(int money) {
	Account::Deposit(money);
	Account::Deposit(money*(specialRate / 100));
}
