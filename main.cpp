#include <iostream>
#include "stock.h"

int main() {
    Stock apple;
    apple.setTicker("AAPL");
    apple.setCompanyName("Apple Inc.");
    apple.setPrice(150.0);
    apple.setTotalShares(1000000);

    std::cout << "Ticker: " << apple.getTicker() << "\n";
    std::cout << "Company: " << apple.getCompanyName() << "\n";
    std::cout << "Price: $" << apple.getPrice() << "\n";
    std::cout << "Total Shares: " << apple.getTotalShares() << "\n";

    return 0;
}