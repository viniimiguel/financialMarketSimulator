#include "events.h"

void Events::inflation(const std::string& currencyName)
{
	for (Currency& currency : currencies)
	{
		if (currency.getName() == currencyName)
		{
			double inflationRate = currency.getVolatility();
			double newSupply = currency.getSupply() * (1 + inflationRate);
			currency.setSupply(newSupply);

			double newValue = currency.getDemand() / newSupply;
			currency.setValue(newValue);

			std::cout << "Currency" << currencyName << "updated after inflation" << std::endl;
			std::cout << "new supply:" << newSupply << ", new value:" << newValue << std::endl;

		}
	}
}
void Events::interestRate(const std::string& currencyName)
{
	for(Currency& currency : currencies)
	{
		if(currency.getName() == currencyName)
		{
			double demand = currency.getDemand();
			double supply = currency.getSupply();
			double volatility = currency.getVolatility();
			double inflation = 0.04; // depois tenho que mudar pra deixar o valor da inflação dinamico nesta função
			double economicGrowth = 0.02; // depois tenho que mudar pra deixar o valor do crescimento econômico dinamico nesta função

			double interestRate = 0.01 * demand / supply + 0.02 * volatility + 0.0005 * inflation - 0.003 * economicGrowth;

			std::cout << "Interest rate for currency " << currencyName << " is " << interestRate << std::endl;

		}
	}
}