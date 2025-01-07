#pragma once

#include <string>
#include <cstdlib>

class Currency
{
private:
	std::string governament;
	std::string name;
	double value;
	double supply;
	double demand;
	double volatility;
public:
	double getValue();
	double getSupply();
	double getDemand();
	double getVolatility();
	std::string getName();
	std::string getGovernament();

	void setValue(double value);
	void setSupply(double supply);
	void setDemand(double demand);
	void setVolatility(double volatility);
	void setName(std::string name);
	void setGovernament(std::string governament);


	void updateValue();

};