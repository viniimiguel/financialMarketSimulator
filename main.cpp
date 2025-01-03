#include <iostream>
#include "httpRequestGroq.h"

int main() {
	RequestGroq* request = new RequestGroq();
	std::string prompt = "rtraduza a frase: oi como voce esta?. para o ingles";
	std::string response;
    request->sendRequest(prompt, response);
	std::cout << "Request sent!" << std::endl;
	std::cout << "Prompt: " << response << std::endl;
	delete request;
    return 0;
}
