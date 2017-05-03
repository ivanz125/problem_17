#include "stdafx.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "BankCard.h"

int main(int argc, char* argv[])
{
	Catch::Session().run(argc, argv);
	system("pause");
	return 0;
}

TEST_CASE("Bank Account"){
	BankAccount* account = new BankAccount();
	CHECK(account->checkPin(1234) == true);
	CHECK(account->getBalance() == 0);
	account->increaseBalance(1000);
	CHECK(account->getBalance() == 1000);
	account->reduceBalance(400);
	CHECK(account->getBalance() == 600);
	account->changePin(8765);
	CHECK(account->checkPin(8765) == true);
}

TEST_CASE("Bank Card"){
	BankAccount* account = new BankAccount();
	account->increaseBalance(1000);
	account->changePin(7412);
	BankCard* card = new BankCard(account);
	CHECK(account->getBalance() == 1000);
	CHECK(card->getBalance() == 1000);
	CHECK(card->checkPin(7412) == true);
	CHECK(card->getCashInAtm(1234, 10) == false);
	CHECK(card->getCashInAtm(1234, 200) == false);
	CHECK(card->getCashInAtm(7412, 5000) == false);
	CHECK(card->getCashInAtm(7412, 500) == true);
	CHECK(card->getCashInAtm(7412, 501) == false);
	CHECK(card->getCashInAtm(7412, 400) == true);
	CHECK(card->getBalance() == 100);
}