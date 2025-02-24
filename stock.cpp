#include "stock.h"

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
std::string Stock::getCompanyName() {
	return companyName;
}
std::string Stock::getTicker() {
	return ticker;
}
double Stock::getPrice() {
	return price;
}
int Stock::getTotalShares() {
	return totalShares;
}
void Stock::updatePrice() {
	
}