class BankAccountAtmInterface{
public:
	virtual int getBalance() = 0;
	virtual bool reduceBalance(int amount) = 0;
	virtual bool checkPin(int pin) = 0;
};