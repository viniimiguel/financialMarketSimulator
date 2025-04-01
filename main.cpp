#include <iostream>
#include "./headerFiles/stock.h"
#include "./headerFiles/util.h"
#include <iomanip>

int main() {


    int count = 0;
    Util u1;
    while (true) {
        for (auto& stock : stocks) {

            stock.sendStockJson();
        }
        for (auto& stock : stocks) {
            auto money = u1.convertCentsToUnit(stock.getPrice());
            stock.setFormatedPrice(money);
            stock.changePrice();
            std::cout << "Updated Ticker: " << stock.getTicker() << "\n";
            std::cout << "Updated Company: " << stock.getCompanyName() << "\n";
            std::cout << "Price: $" << std::fixed << std::setprecision(2) << money << "\n";
            std::cout << "variation: " << stock.getVariation() << "%" << "\n";
            std::cout << "-----------------------------\n";
            std::cout << "numero de iteracoes: " << count << std::endl;
            count++;
        }
    }
}