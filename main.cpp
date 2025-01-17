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
	usd.setDebt(0);
	Currency eur;

	eur.setGovernment("EU");
	eur.setName("EUR");
	eur.setValue(2);
	eur.setSupply(100000);
	eur.setDemand(100000);
	eur.setVolatility(0.05);
	eur.setDebt(0);


	std::cout << usd.getSupply() << std::endl;
	std::cout << eur.getSupply() << std::endl;
	std::cout << usd.getValue() << std::endl;
	std::cout << eur.getValue() << std::endl;
	usd.updateValue();
	eur.updateValue();

	Events events({ &usd, &eur });
	events.governmentLoan("EU", "USA", 200);

	std::cout << usd.getDebt() << std::endl;
	std::cout << eur.getDebt() << std::endl;

	events.publicDebt("EU","USA", 300);
	std::cout << usd.getDebt() << std::endl;
	std::cout << eur.getDebt() << std::endl;

	return 0;
}
