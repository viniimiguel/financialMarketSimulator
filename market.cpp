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
	while (true) {
		if (actived) {
			for (Currency& currency : currencies) {
				std::cout << "Currency Name: " << currency.getName() << std::endl;
				std::cout << "Value: $" << currency.getValue() << std::endl;
				std::cout << "Supply: " << currency.getSupply() << std::endl;
				std::cout << "Demand: " << currency.getDemand() << std::endl;
				std::cout << "---------------------------\n";
				actived = false;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}

