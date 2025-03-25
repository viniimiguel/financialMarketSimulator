#include <iostream>
#include "./headerFiles/stock.h"

int main() {
    Stock apple;
    apple.setTicker("AAPL");
    apple.setCompanyName("Apple Inc.");
    apple.setPrice(150);
    apple.setTotalShares(1000);
    apple.setTotalDemand(1000);

    std::cout << "Ticker: " << apple.getTicker() << "\n";
    std::cout << "Company: " << apple.getCompanyName() << "\n";
    std::cout << "Price: $" << apple.getPrice() << "\n";
    std::cout << "Total Shares: " << apple.getTotalShares() << "\n";
    std::cout << "Total Demand: " << apple.getTotalDemand() << "\n";

    apple.changePrice();

    std::cout << "update price: " << apple.getPrice() << "\n";

    return 0;
}