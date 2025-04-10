
#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>

class Stock {
private:
    std::string ticker;
    std::string companyName;
    long long price = 0;
    double formatedPrice;
    double variation = 0.0;
    std::string country;
    std::string sector;

public:
    Stock(const std::string &ticker, const std::string &company_name, long long price, const std::string &country,
        const std::string &sector)
        : ticker(ticker),
          companyName(company_name),
          price(price),
          country(country),
          sector(sector) {
    }

    void setTicker(std::string ticker);
    void setCompanyName(std::string CompanyName);
    void setPrice(long long price);
    void setFormatedPrice(double price);
    void setVariation(double variation);
    void setCountry(std::string country);
    void setSector(std::string sector);
    std::string getCountry();
    std::string getSector();
    double getFormatedPrice();
    double getVariation();
    std::string getTicker();
    std::string getCompanyName();
    long long getPrice();
    void changePrice();
    void sendStockJson();
};

extern std::vector<Stock> stocks;
#endif