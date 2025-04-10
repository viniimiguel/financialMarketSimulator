#include <iostream>
#include "./headerFiles/stock.h"
#include <chrono>
#include "./headerFiles/cripto.h"
#include "./headerFiles/events.h"
#include "groqIa/groq.h"


int main() {
    Event event;

    event.changeBadPriceBySector("Financial");

    return 0;
}

