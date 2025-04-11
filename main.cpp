#include <iostream>
#include "./headerFiles/stock.h"
#include <chrono>
#include "./headerFiles/events.h"
#include "headerFiles/util.h"
#include <iomanip>
#include <vector>
#include <string>
#include <thread>
#include <random>

#include "groqIa/groq.h"


const std::vector<std::string> sectors = {
    "Advertising", "Aerospace", "Agriculture", "Artificial Intelligence", "Automated Vehicles",
    "Automotive", "Beverage Alcohol", "Biotechnology", "Chemicals", "Cloud Computing",
    "Construction", "Consulting", "Consumer Goods", "Cybersecurity", "Defense",
    "E-commerce", "Education", "Electronics", "Energy", "Entertainment",
    "Fashion", "Financial", "Fintech", "Food & Beverage", "Food Delivery",
    "Forestry", "Gaming", "Green Technology", "Hardware", "Healthcare",
    "Hospitality", "Human Resources", "Information Technology Services", "Insurance",
    "Investment Banking", "Legal", "Logistics", "Luxury Goods", "Marine",
    "Media", "Metals & Mining", "Mining", "Nonprofit", "Packaging",
    "Petrochemicals", "Pharmaceuticals", "Private Equity", "Public Relations", "Publishing",
    "Real Estate", "Renewable Energy", "Retail", "Robotics", "Software",
    "Space Exploration", "Sports", "Technology", "Telecommunications", "Transportation",
    "Travel", "Utilities", "Venture Capital", "Waste Management"
};

int main() {
    Util u1;
    Event event;
    int count = 0;
    auto last_change = std::chrono::steady_clock::now();

    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::minutes>(now - last_change).count();

        if (elapsed >= 50) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, sectors.size() - 1);
            std::string randomSector = sectors[dis(gen)];
            event.changePriceBySector(randomSector);
            last_change = now;
        }


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

            std::this_thread::sleep_for(std::chrono::seconds(2));

            for (auto& stock : stocks) {
                stock.sendStockJson();
            }
        }

    }


    return 0;
}
