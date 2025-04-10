#include "../headerFiles/cripto.h"

long long Cripto::getDemand() {
    return demand;
}
void Cripto::setDemand(long long demand) {
    this->demand = demand;
}
long long Cripto::getShare() {
    return share;
}
void Cripto::setShare(long long share) {
    this->share = share;
}
long long Cripto::getPrice() {
    return price;
}
void Cripto::setPrice(long long price) {
    this->price = price;
}
std::string Cripto::getName() {
    return name;
}
void Cripto::setName(std::string name) {
    this->name = name;
}

