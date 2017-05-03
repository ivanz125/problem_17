#include "BankAccountAtmInterface.h"
#include "BankAccountOtherInterface.h"

class BankAccount : public BankAccountAtmInterface, public BankAccountOtherInterface {

	int balance;
	int pin;

public:
	BankAccount(){
		balance = 0;
		pin = 1234;
	}

	int getBalance(){
		return balance;
	}

	bool reduceBalance(int amount){
		if (amount > balance) return false;
		balance -= amount;
		return true;
	}

	bool checkPin(int pin){
		return this->pin == pin;
	}

	void increaseBalance(int amount){
		balance += amount;
	}

	void changePin(int newPin){
		pin = newPin;
	}
};