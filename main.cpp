#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
#include "market.h"
#include "events.h"
#include <memory>
#include <thread>

int main() {
	std::locale::global(std::locale("en_US.UTF-8"));

	Currency usd;

	usd.setGovernment("USA");
	usd.setName("USD");
	usd.setSupply(100);
	usd.setDemand(100);
	usd.setVolatility(0.05);

	usd.updateValue();

	Currency eur;
	eur.setGovernment("EU");
	eur.setName("EUR");
	eur.setSupply(100);
	eur.setDemand(100);
	eur.setVolatility(0.04);

	eur.updateValue();

	std::cout << "o valor da moeda e: " << usd.getValue() << std::endl;
	Market* mkt = new Market({&usd, &eur});

	Events events({ &usd, &eur }, mkt);


	std::cout << usd.getSupply() << std::endl;

	mkt->displayMarket(events.getActived());
	events.governmentLoan("USA", "EU", 200);
	mkt->displayMarket(events.getActived());


	return 0;
}