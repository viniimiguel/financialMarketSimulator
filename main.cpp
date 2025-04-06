#include <iostream>
#include "./headerFiles/stock.h"
#include "./headerFiles/util.h"
#include "./headerFiles/events.h"
#include <iomanip>
#include <chrono>
#include <thread>

int main() {
    int count = 0;
    Util u1;
    Event e1;

    auto start_time = std::chrono::steady_clock::now();
    auto last_fall = start_time;
    auto last_gain = start_time;
    auto last_big_fall = start_time;
    auto last_big_gain = start_time;

    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed_fall = std::chrono::duration_cast<std::chrono::minutes>(now - last_fall).count();
        auto elapsed_gain = std::chrono::duration_cast<std::chrono::minutes>(now - last_gain).count();
        auto elapsed_big_fall = std::chrono::duration_cast<std::chrono::minutes>(now - last_big_fall).count();
        auto elapsed_big_gain = std::chrono::duration_cast<std::chrono::minutes>(now - last_big_gain).count();


        if (elapsed_fall >= 50) {
            e1.randomizeFall(stocks);
            last_fall = now;
        }
        if (elapsed_gain >= 51) {
            e1.randomizeGain(stocks);
            last_gain = now;
        }
        if (elapsed_big_fall >= 240) {
            e1.randomizeBigFall(stocks);
            last_big_fall = now;
        }
        if (elapsed_big_gain >= 300) {
            e1.randomizeBigGain(stocks);
            last_big_gain = now;
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


        for (auto& stock : stocks) {
            stock.sendStockJson();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}