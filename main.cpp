#include <iostream>
#include "./headerFiles/stock.h"
#include "./headerFiles/util.h"
#include <vector>
#include <iomanip>

int main() {
    std::vector<Stock> stocks(3);

    stocks[0].setTicker("AAPL");
    stocks[0].setCompanyName("Apple Inc.");
    stocks[0].setPrice(6264);
    stocks[0].setTotalShares(5250);
    stocks[0].setTotalDemand(5250);

    stocks[1].setTicker("IBM");
    stocks[1].setCompanyName("IBM Inc.");
    stocks[1].setPrice(140596);
    stocks[1].setTotalShares(1000);
    stocks[1].setTotalDemand(1000);

    stocks[2].setTicker("GOOG");
    stocks[2].setCompanyName("GOOG Inc.");
    stocks[2].setPrice(20073);
    stocks[2].setTotalShares(3400);
    stocks[2].setTotalDemand(3400);

    int count = 0;
    bool control = false;
    while (!control) {
        for (auto& stock : stocks) {

            stock.sendStockJson();
        }
        Util u1;
        for (auto& stock : stocks) {
            auto money = u1.convertCentsToUnit(stock.getPrice());
            stock.setFormatedPrice(money);
            stock.changePrice();
            std::cout << "Updated Ticker: " << stock.getTicker() << "\n";
            std::cout << "Updated Company: " << stock.getCompanyName() << "\n";
            std::cout << "Price: $" << std::fixed << std::setprecision(2) << money << "\n";
            std::cout << "Updated Total Shares: " << stock.getTotalShares() << "\n";
            std::cout << "Updated Total Demand: " << stock.getTotalDemand() << "\n";
            std::cout << "variation: " << stock.getVariation() << "%" << "\n";
            std::cout << "-----------------------------\n";

            std::cout << "numero de iteracoes: " << count << std::endl;
            count++;

        }
    }
}