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
	Events(std::vector<Currency> currencies) : currencies(currencies) {}
	void inflation(std::string& currencyName);
};