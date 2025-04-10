#include <iostream>
#include "./headerFiles/stock.h"
#include "./headerFiles/util.h"
#include "./headerFiles/events.h"
#include <iomanip>
#include <chrono>
#include <thread>
#include "./headerFiles/cripto.h"

int main() {
    for (auto& stock : stocks) {
        std::cout << "nome" << stock.getCompanyName() << std::endl;
        std::cout << "preço: " << stock.getPrice() << std::endl;
    }
    for (auto& cripto : criptos) {
        std::cout << "nome" << cripto.getName() << std::endl;
        std::cout << "preço: " << cripto.getPrice() << std::endl;
        std::cout << "share: " << cripto.getShare() << std::endl;
        std::cout << "demand:" << cripto.getDemand() << std::endl;
    }

}