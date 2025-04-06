#include "../headerFiles/events.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Event::randomize(std::vector<Stock> &stocks, double percent, double variation) {
    if (stocks.empty()) return;

    int index = rand() % stocks.size();

    long long currentPrice = stocks[index].getPrice();

    if (currentPrice <= 0) {
        std::cerr << "[ERRO] Preço inválido para " << stocks[index].getCompanyName() << ": " << currentPrice << "\n";
        return;
    }

    std::cout << "antes a empresa: " << stocks[index].getCompanyName() << " valia: " << currentPrice << std::endl;

    double newPriceDouble = static_cast<double>(currentPrice) * percent;
    long long newPrice = static_cast<long long>(newPriceDouble);

    if (newPrice <= 0) {
        newPrice = 1;
    }

    stocks[index].setPrice(newPrice);
    stocks[index].setVariation(variation);

    std::cout << "a ação: " << stocks[index].getCompanyName()
              << " agora vale: " << stocks[index].getPrice()
              << " variação de: " << stocks[index].getVariation() << std::endl;
}

void Event::randomizeFall(std::vector<Stock> &stocks) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    double randomMultiplier = 0.1 + (std::rand() % 81) / 100.00;
    int variation = static_cast<int>((randomMultiplier - 1.0) * 100);
    std::cout << "valor randomico: " << randomMultiplier << "valor variation: "<< variation<<std::endl;
    randomize(stocks, randomMultiplier, variation);
}

void Event::randomizeGain(std::vector<Stock> &stocks) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    double randomMultiplier = 1.1 + (std::rand() % 81) / 100.00;
    int variation = static_cast<int>((randomMultiplier - 1.0) * 100);
    std::cout << "valor randomico: " << randomMultiplier << "valor variation: "<< variation<<std::endl;
    randomize(stocks, randomMultiplier, variation);
}
void Event::randomizeBigFall(std::vector<Stock> &stocks) {
    randomize(stocks, 0.1, -90 );
}
void Event::randomizeBigGain(std::vector<Stock> &stocks) {
    randomize(stocks, 2.0, 100);
}