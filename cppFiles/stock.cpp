#include "../headerFiles/stock.h"

void Stock::setTicker(std::string ticker) {
    this->ticker = ticker;
}
void Stock::setCompanyName(std::string companyName) {
    this->companyName = companyName;
}
void Stock::setPrice(double price) {
    this->price = price;
}
void Stock::setTotalShares(int totalShares) {
    this->totalShares = totalShares;
}
void Stock::setTotalDemand(int totalDemand) {
    this->totalDemand = totalDemand;
}

std::string Stock::getCompanyName() {
    return companyName;
}
std::string Stock::getTicker() {
    return ticker;
}
int Stock::getTotalShares() {
    return totalShares;
}
double Stock::getPrice() {
    return price;
}
int Stock::getTotalDemand() {
    return totalDemand;
}
void Stock::changePrice() {
    if (totalShares + totalDemand == 0) return;
    double imbalance = (totalDemand - totalShares) / static_cast<double>(totalShares + totalDemand);
    price = price * (1 + imbalance);
}
