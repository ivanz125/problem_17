class BankAccountOtherInterface{
public:
	virtual void increaseBalance(int amount) = 0;
	virtual void changePin(int newPin) = 0;
};