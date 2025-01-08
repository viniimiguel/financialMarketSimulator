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
	usd.setSupply(100300);
	usd.setDemand(100100);
	usd.setVolatility(0.05);

	
	std::cout << "Initial value of USD: " << usd.getValue() << std::endl;
	usd.updateValue();
	std::cout << "Value of USD after update: " << usd.getValue() << std::endl;

	Events events({ &usd });

	events.underSupply("USD");
	std::cout << "Value of USD after demand shock: " << usd.getValue() << std::endl;

	return 0;
}
