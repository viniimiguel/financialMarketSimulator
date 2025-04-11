#include <iostream>
#include "./headerFiles/stock.h"
#include <chrono>
#include "./headerFiles/cripto.h"
#include "./headerFiles/events.h"
#include "groqIa/groq.h"
#include "headerFiles/util.h"
#include <iomanip>


int main() {
    Util u1;
    Event event;
    int count = 0;

    for (int i =0; i<2; i++) {
        for (auto& stock : stocks) {
            auto money = u1.convertCentsToUnit(stock.getPrice());
            stock.changePrice();
            stock.setFormatedPrice(money);


            std::cout << "Updated Ticker: " << stock.getTicker() << "\n";
            std::cout << "Updated Company: " << stock.getCompanyName() << "\n";
            std::cout << "Price: $" << std::fixed << std::setprecision(2) << money << "\n";
            std::cout << "variation: " << stock.getVariation() << "%" << "\n";
            std::cout << "country: " << stock.getCountry() << "\n";
            std::cout << "sector: " << stock.getSector() << "\n";
            std::cout << "-----------------------------\n";
            std::cout << "numero de iteracoes: " << count << std::endl;
            count++;
        }



        for (auto& stock : stocks) {
            stock.sendStockJson();
        }
    }

    return 0;
}
