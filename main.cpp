#include <iostream>
#include "httpRequestGroq.h"
#include <locale>

int main() {
    std::string input;
    std::cout << "Testando implementação..." << std::endl;
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());
    while (true) {
        std::cout << "Digite o prompt (ou 'exit' para sair): ";
        std::getline(std::cin, input);

        if (input == "exit")
            break;

        RequestGroq* request = new RequestGroq();
        std::string response;

        request->sendRequest(input, response);
        delete request;

        std::cout << "Resposta: " << response << std::endl;
    }

    return 0;
}
