#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
#include "market.h"
#include "events.h"

int main() {
	std::locale::global(std::locale("en_US.UTF-8"));

	Currency usd;

	usd.setGovernament("USA");
	usd.setName("USD");
	usd.setValue(1.0);
	usd.setSupply(1000000);
	usd.setDemand(1000000);
	usd.setVolatility(0.05);

	
	std::cout << "Initial value of USD: " << usd.getValue() << std::endl;
	usd.updateValue();
	std::cout << "Value of USD after update: " << usd.getValue() << std::endl;

	Events events({ usd });
	std::cout << usd.getDemand() << std::endl;
	std::cout << usd.getValue() << std::endl;
	events.demandShock("USD");
	std::cout << usd.getDemand() << std::endl;
	std::cout << usd.getValue() << std::endl;
	return 0;
}
