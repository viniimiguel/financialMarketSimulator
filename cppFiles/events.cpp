#include "../headerFiles/events.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

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
void Event::changePriceBySector(const std::string& targetSector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(10.0, 100.0);

    for (auto& stock : stocks) {
        if (stock.getSector() == targetSector) {
            double percentageChange = dis(gen);

            long long currentPrice = stock.getPrice();
            if (currentPrice <= 0) {
                std::cerr << "[ERRO] Preço inválido para " << stock.getCompanyName()
                          << ": " << currentPrice << "\n";
                continue;
            }
            double newPriceDouble = static_cast<double>(currentPrice) * (1.0 + percentageChange / 100.0);
            long long newPrice = static_cast<long long>(newPriceDouble);

            if (newPrice <= 0) {
                newPrice = 1;
            }
            stock.setPrice(newPrice);
            stock.setVariation(percentageChange);
            std::cout << "Empresa: " << stock.getCompanyName()
                      << " | Preço Antigo: " << currentPrice
                      << " | Novo Preço: " << stock.getPrice()
                      << " | Variação: " << stock.getVariation() << "%\n";
        }
    }
}

void Event::changeBadPriceBySector(const std::string& targetSector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, -99.0);

    for (auto& stock : stocks) {
        if (stock.getSector() == targetSector) {
            double percentageChange = dis(gen);

            long long currentPrice = stock.getPrice();
            if (currentPrice <= 0) {
                std::cerr << "[ERRO] Preço inválido para " << stock.getCompanyName()
                          << ": " << currentPrice << "\n";
                continue;
            }
            double newPriceDouble = static_cast<double>(currentPrice) * (1.0 + percentageChange / 100.0);
            long long newPrice = static_cast<long long>(newPriceDouble);

            if (newPrice <= 0) {
                newPrice = 1;
            }
            stock.setPrice(newPrice);
            stock.setVariation(percentageChange);
            std::cout << "Empresa: " << stock.getCompanyName()
                      << " | Preço Antigo: " << currentPrice
                      << " | Novo Preço: " << stock.getPrice()
                      << " | Variação: " << stock.getVariation() << "%\n";
        }
    }
}