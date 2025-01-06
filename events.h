#pragma once
#include <vector>
#include "currency.h"
#include <cstdlib>


// essa classe vai ser responsavel por gerar eventos aleatorios de crise no mercado financeiro
// estudar sobre eventos que acontecem no mercado de finanças

class Events
{
private:
	std::vector<Currency> currencies;
public:
	Events(std::vector<Currency> currencies) : currencies(currencies) {}
	void inflation(std::string& currencyName);
};