#include "market.h"
#include <iostream>

void Market::addCurrency(Currency currency)
{
	currencies.push_back(currency);
}

void Market::updateMakert()
{
	for (Currency& currency : currencies)
	{
		currency.updateValue();
	}
}

void Market::displayMarket() {
    for (Currency& currency : currencies) {
        std::cout << "Currency Name: " << currency.getName() << "\n";
        std::cout << "Value: $" << currency.getValue() << "\n";
        std::cout << "Supply: " << currency.getSupply() << "\n";
        std::cout << "Demand: " << currency.getDemand() << "\n";
        std::cout << "---------------------------\n";
    }
}

