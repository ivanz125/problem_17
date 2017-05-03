#include "BankAccount.h"

class BankCard : public BankAccountAtmInterface {

	BankAccount* account;
	bool reduceBalance(int amount){ return false; };

public:
	BankCard(BankAccount* account){
		this->account = account;
	}

	int getBalance(){
		return account->getBalance();
	}

	bool checkPin(int pin){
		return account->checkPin(pin);
	}

	bool getCashInAtm(int pin, int amount){
		if (!checkPin(pin) || account->getBalance() < amount) return false;
		account->reduceBalance(amount);
		return true;
	}
};