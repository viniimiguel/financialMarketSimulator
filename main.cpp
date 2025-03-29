#include <iostream>
#include "./headerFiles/stock.h"

int main() {
    Stock apple;
    apple.setTicker("AAPL");
    apple.setCompanyName("Apple Inc.");
    apple.setPrice(150);
    apple.setTotalShares(10600);
    apple.setTotalDemand(10070);

    std::cout << "Ticker: " << apple.getTicker() << "\n";
    std::cout << "Company: " << apple.getCompanyName() << "\n";
    std::cout << "Price: $" << apple.getPrice() << "\n";
    std::cout << "Total Shares: " << apple.getTotalShares() << "\n";
    std::cout << "Total Demand: " << apple.getTotalDemand() << "\n";

    apple.changePrice();

    std::cout << "update price: " << apple.getPrice() << "\n";
    apple.sendStockJson();

    Stock ibm;

    ibm.setTicker("ibm");
    ibm.setCompanyName("ibm Inc.");
    ibm.setPrice(50);
    ibm.setTotalShares(100);
    ibm.setTotalDemand(10070);
    ibm.changePrice();

    ibm.sendStockJson();
    std::cout << "Ticker: " << ibm.getTicker() << "\n";
    std::cout << "Company: " << ibm.getCompanyName() << "\n";
    std::cout << "Price: $" << ibm.getPrice() << "\n";
    std::cout << "Total Shares: " << ibm.getTotalShares() << "\n";
    std::cout << "Total Demand: " << ibm.getTotalDemand() << "\n";
    return 0;
}