#include <iostream>
#include "httpRequestGroq.h"
#include <locale>
#include "currency.h"
int main() {
	std::locale::global(std::locale("en_US.UTF-8"));

	Currency* currency = new Currency();
	currency->setValue(0.1);
	currency->getValue();
	std::cout << currency->getValue() << std::endl;
    return 0;
}
