#pragma once

#include <string>

class Stock {
private:
    std::string ticker;
    std::string companyName;
    double price = 0.0;
    int totalShares;
    int totalDemand;

public:
    void setTicker(std::string ticker);
    void setCompanyName(std::string CompanyName);
    void setPrice(double price);
    void setTotalShares(int totalShares);
    void setTotalDemand(int totalDemand);
    std::string getTicker();
    std::string getCompanyName();
    double getPrice();
    int getTotalShares();
    int getTotalDemand();
    void changePrice();
    void sendStockJson();

};