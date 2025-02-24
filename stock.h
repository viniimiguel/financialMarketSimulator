#pragma once

#include <string>
#include <cstdlib>

class Stock
{
private:
	std::string ticker;
	std::string companyName;
	double price = 0.0;
	int totalShares;

public:
	void setTicker(std::string ticker);
	void setCompanyName(std::string CompanyName);
	void setPrice(double price);
	void setTotalShares(int totalShares);
	std::string getTicker();
	std::string getCompanyName();
	double getPrice();
	int getTotalShares();
	void updatePrice();

};