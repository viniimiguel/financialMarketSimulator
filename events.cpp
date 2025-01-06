#include "events.h"

void Events::inflation(std::string& currencyName)
{
	for (Currency& currency : currencies)
	{
		if (currency.getName() == currencyName)
		{
			double inflationRate = currency.getVolatility();
			double newSupply = currency.getSupply() * (1 + inflationRate);
			currency.setSupply(newSupply);

			double newValue = currency.getDemand() / newSupply;


		}
	}
}