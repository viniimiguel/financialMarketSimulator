#include <iostream>
#include "./headerFiles/stock.h"
#include <chrono>
#include "./headerFiles/cripto.h"

int main() {
    while (true) {
        for (auto& cripto : criptos) {
            cripto.changePrice();
            std::cout << "nome" << cripto.getName() << std::endl;
            std::cout << "preço: " << cripto.getPrice() << std::endl;
            std::cout << "share: " << cripto.getShare() << std::endl;
            std::cout << "demand:" << cripto.getDemand() << std::endl;
        }
    }


}