#include "../headerFiles/events.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Event::randomize(std::vector<Stock> &stocks, double percent, double variation) {
    if (stocks.empty()) return;

    srand(time(nullptr));
    int index = rand() % stocks.size();
    std::cout << "antes a empresa: " << stocks[index].getCompanyName() << "valia: " << stocks[index].getPrice() << std::endl;
    long long currentPrice = stocks[index].getPrice();
    long long newPrice = currentPrice * percent;
    stocks[index].setPrice(newPrice);
    stocks[index].setVariation(variation);

    std::cout << "a ação: " << stocks[index].getCompanyName() << "agora vale: " << stocks[index].getPrice() << "variação de: " << stocks[index].getVariation() <<std::endl;
}

void Event::randomizeFall(std::vector<Stock> &stocks) {
   randomize(stocks, 0.8, -20);
}

void Event::randomizeGain(std::vector<Stock> &stocks) {
   randomize(stocks, 1.2, 20.00);
}
void Event::randomizeBigFall(std::vector<Stock> &stocks) {
    randomize(stocks, 0.1, -90 );
}
void Event::randomizeBigGain(std::vector<Stock> &stocks) {
    randomize(stocks, 2.0, 100);
}