#pragma once
#include "currency.h"
#include <vector>


class Market
{
private:
	std::vector<Currency*> currencies;
public:
	Market(std::vector<Currency*> currencies) : currencies(currencies) {}
	void updateMakert();
	void displayMarket(bool actived);
};
