#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
#include "market.h"
#include "events.h"

int main() {
	std::locale::global(std::locale("en_US.UTF-8"));

	Currency usd;

	usd.setGovernment("USA");
	usd.setName("USD");
	usd.setValue(1.0);
	usd.setSupply(100300);
	usd.setDemand(100100);
	usd.setVolatility(0.05);

	Currency eur;

	eur.setGovernment("EU");
	eur.setName("EUR");
	eur.setValue(0.8);
	eur.setSupply(100000);
	eur.setDemand(100000);
	eur.setVolatility(0.05);

	Events events({ &usd, &eur });
	events.governmentLoan("EU", "USA", 100);

	return 0;
}
