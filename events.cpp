#include "events.h"
#include <memory>
#include "market.h"

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
		}
	}
	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);
}
void Events::interestRate(const std::string& currencyGovernment)
{
	for(Currency* currency : currencies)
	{
		if(currency->getGovernment() == currencyGovernment)
		{
			double demand = currency->getDemand();
			double supply = currency->getSupply();
			double volatility = currency->getVolatility();
			double inflation = 0.04; // depois tenho que mudar pra deixar o valor da inflação dinamico nesta função
			double economicGrowth = 0.02; // depois tenho que mudar pra deixar o valor do crescimento econômico dinamico nesta função

			double interestRate = 0.01 * demand / supply + 0.02 * volatility + 0.0005 * inflation - 0.003 * economicGrowth;

		}
	}
	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);
}
void Events::publicDebt(const std::string& currencyGovernment, const std::string& currencyDebtGovernment, double debt)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(1.4, 2.4);

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
	if (debt > governmentCurrency->getDebt()) {
		std::cerr << "voce nao pode pagar mais do que deve voce pagou apenas a sua divida." << std::endl;
		debt = governmentCurrency->getDebt();
	}
	double convertCurrency = debt * governmentCurrency->getValue() / debtCurrency->getValue();
	double newSupplyGovernment = debtCurrency->getSupply() + convertCurrency;
	debtCurrency->setSupply(newSupplyGovernment);

	double newCurrencySupply = governmentCurrency->getSupply() - convertCurrency;
	governmentCurrency->setSupply(newCurrencySupply);

	governmentCurrency->setDebt(0);

	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);

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
		std::cerr << "Erro: Nao foi possível encontrar as moedas especificadas." << std::endl;
		return;
	}
	if (loan > loanCurrency->getSupply()) {
		std::cerr << "Erro: Nao e possivel emprestar mais do que voce tem!" << std::endl;
		return;
	}
	double convertedLoan = loan * loanCurrency->getValue() / governmentCurrency->getValue();

	double newSupplyGovernment = governmentCurrency->getSupply() + convertedLoan;
	double newSupplyLoan = loanCurrency->getSupply() - loan;

	governmentCurrency->setSupply(newSupplyGovernment);
	governmentCurrency->setDebt(loan);

	loanCurrency->setSupply(newSupplyLoan);

	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);
	
}
void Events::underDemand(const std::string& currencyGovernment)
{
	for(Currency* currency : currencies)
	{
		if(currency->getGovernment() == currencyGovernment)
		{
			if (currency->getDemand() < currency->getSupply()) {
				std::cerr << "a demanda ja e menor que a oferta" << std::endl;
				if (mkt) {
					mkt->updateMakert();
					mkt->displayMarket(actived);
				}
				setActived(true);
				return;
			}
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
	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);
}
void Events::overDemand(const std::string& currencyGovernment)
{
	for(Currency* currency : currencies)
	{
		if(currency->getGovernment() == currencyGovernment)
		{
			if (currency->getDemand() > currency->getSupply()) {
				std::cerr << "demanda ja e maior que a oferta" << std::endl;
				if (mkt) {
					mkt->updateMakert();
					mkt->displayMarket(actived);
				}
				setActived(true);
				return;
			}
			double overDemand = currency->getSupply() * 0.1;
			double newDemand = currency->getSupply() + overDemand;
			currency->setDemand(newDemand);
			double newValue = currency->getDemand() / currency->getSupply();
			currency->setValue(newDemand);
		}
	}
	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);
}
void Events::overSupply(const std::string& currencyGovernment) {
	for (Currency* currency : currencies) {
		if (currency->getGovernment() == currencyGovernment) {
			if (currency->getSupply() > currency->getDemand()) {
				std::cerr << "a oferta ja e maior que a demanda" << std::endl;
				if (mkt) {
					mkt->updateMakert();
					mkt->displayMarket(actived);
				}
				setActived(true);
				return;
			}
			double overSupply = currency->getDemand() * 0.1;
			double newSupply = currency->getDemand() + overSupply;
			currency->setSupply(newSupply);
			currency->setValue(overSupply);
		}
	}
	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);
}
void Events::underSupply(const std::string& currencyGovernment)
{
	for (Currency* currency : currencies)
	{
		if (currency->getGovernment() == currencyGovernment)
		{
			if (currency->getSupply() < currency->getDemand()) {
				std::cerr << "a oferta ja e menor que a demanda" << std::endl;
				if (mkt) {
					mkt->updateMakert();
					mkt->displayMarket(actived);
				}
				setActived(true);
				return;
			}
			double underSupply = currency->getDemand() * 0.1;
			double newSupply = currency->getSupply() - underSupply;
			currency->setSupply(newSupply);
			currency->setValue(newSupply);
		}
	}
	if (mkt) {
		mkt->updateMakert();
		mkt->displayMarket(actived);
	}
	setActived(true);
}