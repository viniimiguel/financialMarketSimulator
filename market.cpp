#include "market.h"
#include <iostream>
#include <thread>
#include <chrono>

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
void Market::displayMarket(bool actived) {
    if (actived) {
        for (Currency& currency : currencies) {
            std::cout << "Currency Name: " << currency.getName() << "\n";
            std::cout << "Value: $" << currency.getValue() << "\n";
            std::cout << "Supply: " << currency.getSupply() << "\n";
            std::cout << "Demand: " << currency.getDemand() << "\n";
            std::cout << "---------------------------\n";
        }
    }
    
}
    
