#pragma once

#include <string>

class Stock {
private:
    std::string ticker;
    std::string companyName;
    long long price = 0;
    long long  totalShares;
    long long  totalDemand;
    double formatedPrice;
    double variation = 0.0;

public:
    void setTicker(std::string ticker);
    void setCompanyName(std::string CompanyName);
    void setPrice(long long price);
    void setTotalShares(long long totalShares);
    void setTotalDemand(long long totalDemand);
    void setFormatedPrice(double price);
    void setVariation(double variation);
    double getFormatedPrice();
    double getVariation();
    std::string getTicker();
    std::string getCompanyName();
    long long getPrice();
    long long getTotalShares();
    long long getTotalDemand();
    void changePrice();
    void sendStockJson();
};