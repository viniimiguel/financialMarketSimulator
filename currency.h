#pragma once

#include <string>
#include <cstdlib>

class Currency
{
private:
	std::string government;
	std::string name;
	double value;
	double supply;
	double demand;
	double volatility;
	double debt;
public:
	double getValue();
	double getSupply();
	double getDemand();
	double getVolatility();
	double getDebt();
	std::string getName();
	std::string getGovernment();

	void setValue(double value);
	void setSupply(double supply);
	void setDemand(double demand);
	void setVolatility(double volatility);
	void setName(std::string name);
	void setGovernment(std::string government);
	void setDebt(double debt);


	void updateValue();

};