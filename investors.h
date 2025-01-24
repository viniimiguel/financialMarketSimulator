#pragma once
#include "currency.h"
#include <vector>
#include "market.h"

class Investors {
private:
	Currency* currencie;
	struct Wallet {
		std::string currencyName;
		int amount;
	};
	std::vector<Wallet> currencies;

public:
	void sellCurrency(const std::string& currencyName, const std::string& investorsName, int amount);
	void buyCurrency(const std::string& currencyName, const std::string& investorsName, int amount);
};