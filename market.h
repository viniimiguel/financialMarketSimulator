#pragma once
#include "currency.h"
#include <vector>


class Market
{
private:
	std::vector<Currency> currencies;
public:
	void addCurrency(Currency currency);
	void updateMakert();
	void displayMarket();
};
