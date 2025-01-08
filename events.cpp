#include "events.h"


void Events::inflation(const std::string& currencyName)
{
	for (Currency* currency : currencies)
	{
		if (currency->getName() == currencyName)
		{
			double inflationRate = currency->getVolatility();
			double newSupply = currency->getSupply() * (1 + inflationRate);
			currency->setSupply(newSupply);

			double newValue = currency->getDemand() / newSupply;
			currency->setValue(newValue);

			std::cout << "Currency" << currencyName << "updated after inflation" << std::endl;
			std::cout << "new supply:" << newSupply << ", new value:" << newValue << std::endl;

		}
	}
}
void Events::interestRate(const std::string& currencyName)
{
	for(Currency* currency : currencies)
	{
		if(currency->getName() == currencyName)
		{
			double demand = currency->getDemand();
			double supply = currency->getSupply();
			double volatility = currency->getVolatility();
			double inflation = 0.04; // depois tenho que mudar pra deixar o valor da inflação dinamico nesta função
			double economicGrowth = 0.02; // depois tenho que mudar pra deixar o valor do crescimento econômico dinamico nesta função

			double interestRate = 0.01 * demand / supply + 0.02 * volatility + 0.0005 * inflation - 0.003 * economicGrowth;

			std::cout << "Interest rate for currency " << currencyName << " is " << interestRate << std::endl;

		}
	}
}
void Events::publicDebt(const std::string& currencyGovernment, const std::string& currencyDebtGovernment, double debt)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.05, 1.4);

	double randomFees = dis(gen);
	Currency* governmentCurrency = nullptr;
	Currency* debtCurrency = nullptr;

	for(Currency* currency : currencies)
	{
		

		if(currency->getGovernment() == currencyGovernment)
		{
			governmentCurrency = currency;
		}
		else if (currency->getGovernment() == currencyDebtGovernment)
		{
			debtCurrency = currency;
		}
		if(governmentCurrency && debtCurrency)
		{
			break;
		}
	}
	if(!governmentCurrency || !debtCurrency)
	{
		std::cerr << "Erro: Não foi possível encontrar as moedas especificadas." << std::endl;
	}
	double convertCurrency = NULL;
}
void Events::governmentLoan(const std::string& currencyGovernment, const std::string& currencyLoanGovernment, double loan)
{
	Currency* governmentCurrency = nullptr;
	Currency* loanCurrency = nullptr;

	for (Currency* currency : currencies)
	{
		if (currency->getGovernment() == currencyGovernment)
		{
			governmentCurrency = currency;
		}
		else if (currency->getGovernment() == currencyLoanGovernment)
		{
			loanCurrency = currency;
		}

		if (governmentCurrency && loanCurrency)
		{
			break;
		}
	}

	if (!governmentCurrency || !loanCurrency)
	{
		std::cerr << "Erro: Não foi possível encontrar as moedas especificadas." << std::endl;
		return;
	}

	double convertedLoan = loan * loanCurrency->getValue() / governmentCurrency->getValue();

	double newSupplyGovernment = governmentCurrency->getSupply() + convertedLoan;
	double newSupplyLoan = loanCurrency->getSupply() - loan;

	governmentCurrency->setSupply(newSupplyGovernment);
	governmentCurrency->setDebt(loan);

	loanCurrency->setSupply(newSupplyLoan);

	std::cout << "Novo supply de " << governmentCurrency->getName() << ": " << governmentCurrency->getSupply() << std::endl;
	std::cout << "Novo supply de " << loanCurrency->getName() << ": " << loanCurrency->getSupply() << std::endl;
}
void Events::demandShock(const std::string& currencyName)
{
	for(Currency* currency : currencies)
	{
		if(currency->getName() == currencyName)
		{
			double demandShock = currency->getSupply() * 0.1;
			double newDemand = currency->getDemand() - demandShock;
			currency->setDemand(newDemand);
			double newValue = currency->getDemand() / currency->getSupply();
			currency->setValue(newValue);
			std::cout << newValue << std::endl;
		}
		else
		{
			std::cout << "Currency not found" << std::endl;
		}
	}
}
void Events::overDemand(const std::string& currencyName)
{
	for(Currency* currency : currencies)
	{
		if(currency->getName() == currencyName)
		{
			double overDemand = currency->getDemand() * 0.2;
			double newDemand = currency->getDemand() + overDemand;
			currency->setDemand(newDemand);
			double newValue = currency->getDemand() / currency->getSupply();
			currency->setValue(newValue);
		}
	}
}
void Events::overSupply(const std::string& currencyName) {
	for (Currency* currency : currencies) {
		if (currency->getName() == currencyName) {
			double overSupply = currency->getDemand() * 0.1;
			double newSupply = currency->getSupply() + overSupply;
			currency->setSupply(newSupply);
			double newValue = currency->getDemand() / newSupply;
			currency->setValue(newValue);
		}
	}
}
void Events::underSupply(const std::string& currencyName)
{
	for (Currency* currency : currencies)
	{
		if (currency->getName() == currencyName)
		{
			double underSupply = currency->getDemand() * 0.1;
			double newSupply = currency->getSupply() - underSupply;
			if (newSupply < 0.1) {
				newSupply = 0.1;
			}
			currency->setSupply(newSupply);
			double newValue = currency->getDemand() / (newSupply + 1e-6);
			currency->setValue(newValue);
		}
	}
}

