#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
int main() {
	std::locale::global(std::locale("en_US.UTF-8"));

	Currency* currency = new Currency();
	currency->setName("dollar");
	currency->setValue(1.0);
	currency->setSupply(1e12);
	currency->setDemand(9.8e11);
	currency->setVolatility(0.005);
	for (int i = 0; i < 100; i++)
	{
		currency->updateValue();

		std::cout << currency->getName() << std::endl;
		std::cout << currency->getValue() << std::endl;
	}
	
	
    return 0;
}
