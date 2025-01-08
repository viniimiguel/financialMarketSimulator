#pragma once
#include <vector>
#include "currency.h"
#include <cstdlib>
#include <iostream>

class Events
{
private:
	std::vector<Currency*> currencies;
public:
	Events(const std::vector<Currency*>& currencies) : currencies(currencies){}
	void inflation(const std::string& currencyName);
	void interestRate(const std::string& currencyName);
	void publicDebt(const std::string& currencyGovernment, const std::string& currencyDebtGovernment);
	void governmentLoan(const std::string& currencyGovernment,const std::string& currencyLoanGovernment);
	void pib(const std::string& currencyGovernment);
	void demandShock(const std::string& currencyName);
	void overDemand(const std::string& currencyName);
	void overSupply(const std::string& currencyName);
	void underSupply(const std::string& currencyName);
};