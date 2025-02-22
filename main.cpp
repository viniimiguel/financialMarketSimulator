#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
#include "market.h"
#include "events.h"
#include <memory>
#include <thread>

Currency createCurrencies(const std::string& name, const std::string& government, float supply, float volatility) {
	Currency currency;
	currency.setName(name);
	currency.setGovernment(government);
	currency.setSupply(supply);
	currency.setDemand(supply);
	currency.setVolatility(volatility);
	currency.updateValue();
	return currency;
}
int main() {
    std::locale::global(std::locale("en_US.UTF-8"));

    Currency usd = createCurrencies("USD", "USA", 10000, 0.05);
    Currency eur = createCurrencies("EUR", "EU", 1000, 0.04);

    std::cout << "O valor da moeda USD é: " << usd.getValue() << std::endl;
    std::cout << "O valor da moeda EUR é: " << eur.getValue() << std::endl;

    Market* mkt = new Market({ &usd, &eur });
    Events events({ &usd, &eur }, mkt);

    events.underDemand("EU");
    mkt->displayMarket(events.getActived());

    delete mkt;
    return 0;
}