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
	double randomFactor = ((rand() % 200) - 100.0) / 1000.0;
	value += demand / supply + randomFactor * volatility;
	if (value < 0.01) value = 0.01;
}