#pragma once

#include <string>
#include <vector>

class Stock {
private:
    std::string ticker;
    std::string companyName;
    long long price = 0;
    double formatedPrice;
    double variation = 0.0;

public:
    Stock(const std::string &ticker, const std::string &company_name, long long price)
        : ticker(ticker),
          companyName(company_name),
          price(price) {
    }

    void setTicker(std::string ticker);
    void setCompanyName(std::string CompanyName);
    void setPrice(long long price);
    void setFormatedPrice(double price);
    void setVariation(double variation);
    double getFormatedPrice();
    double getVariation();
    std::string getTicker();
    std::string getCompanyName();
    long long getPrice();
    void changePrice();
    void sendStockJson();
};

extern std::vector<Stock> stocks;