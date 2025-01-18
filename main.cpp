#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
#include "market.h"
#include "events.h"
#include <thread>

int main() {
	std::locale::global(std::locale("en_US.UTF-8"));

	Currency usd;

	usd.setGovernment("USA");
	usd.setName("USD");
	usd.setSupply(100300);
	usd.setDemand(100100);
	usd.setVolatility(0.05);
	usd.setDebt(0);
	Currency eur;

	eur.setGovernment("EU");
	eur.setName("EUR");
	eur.setSupply(100000);
	eur.setDemand(100000);
	eur.setVolatility(0.05);
	eur.setDebt(0);

	Market* mkt = new Market();
	Events events({ &usd, &eur }, mkt);
	mkt->addCurrency(usd);
	mkt->addCurrency(eur);
	usd.updateValue();
	eur.updateValue();
	mkt->displayMarket(true);
	events.governmentLoan("USA", "EU", 1000);
	mkt->displayMarket(events.getActived());






	delete mkt;
	return 0;
}