#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
#include "market.h"


int main() {
	std::locale::global(std::locale("en_US.UTF-8"));

	Currency usd;

	usd.setName("USD");
	usd.setValue(1.0);
	usd.setSupply(1000000);
	usd.setDemand(1000000);
	usd.setVolatility(0.01);

	Currency eur;

	eur.setName("EUR");
	eur.setValue(0.8);
	eur.setSupply(1000000);
	eur.setDemand(1000000);
	eur.setVolatility(0.01);

	Market market;

	market.addCurrency(usd);
	market.addCurrency(eur);
	market.displayMarket();


	for(int i = 0; i < 10; i++)
	{
		market.updateMakert();
		market.displayMarket();
	}
	
    return 0;
}
