#pragma once
#include <vector>
#include "currency.h"
#include <cstdlib>
#include <iostream>

class Events
{
private:
	std::vector<Currency> currencies;
public:
	Events(const std::vector<Currency>& currencies) : currencies(currencies){}
	void inflation(const std::string& currencyName);
	void interestRate(const std::string& currencyName);
	void publicDebt(const std::string& currencyName);
};