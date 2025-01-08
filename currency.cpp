#include "currency.h"

double Currency::getValue()
{
	return value;
}

void Currency::setValue(double value)
{
	this->value = value;
}

double Currency::getSupply()
{
	return supply;
}

void Currency::setSupply(double supply)
{
	this->supply = supply;
}

double Currency::getDemand()
{
	return demand;
}

void Currency::setDemand(double demand)
{
	this->demand = demand;
}

double Currency::getVolatility()
{
	return volatility;
}

void Currency::setVolatility(double volatility)
{
	this->volatility = volatility;
}

void Currency::updateValue()
{
	if(supply > 0)
	{
		double baseValue = demand / supply;
		double randomFactor = ((rand() % 200) - 100) / 100.0;
		value = baseValue * (1 + randomFactor * volatility);
	}
	else
	{
		value = 0;
	}
}


std::string Currency::getName()
{
	return name;
}

void Currency::setName(std::string name)
{
	this->name = name;
}

std::string Currency::getGovernment()
{
	return government;
}

void Currency::setGovernment(std::string government)
{
	this->government = government;
}

