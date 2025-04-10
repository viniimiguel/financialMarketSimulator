#include <iostream>
#include "./headerFiles/stock.h"
#include <chrono>
#include "./headerFiles/cripto.h"
#include "./headerFiles/events.h"
#include "groqIa/groq.h"


int main() {
    Groq groq;
    std::string godNotice = groq.sendGodNotice("tecnologia");
    std::cout << "Resposta otimista: " << godNotice << std::endl;

    std::string badNotice = groq.sendBadNotice("energia");
    std::cout << "Resposta pessimista: " << badNotice << std::endl;

    return 0;
}

