#include "../headerFiles/cripto.h"
#include <curl/curl.h>
#include <iostream>
#include <ctime>
#include <random>


long long Cripto::getDemand() {
    return this->demand;
}
void Cripto::setDemand(long long demand) {
    this->demand = demand;
}
long long Cripto::getShare() {
    return this->share;
}

void Cripto::setShare(long long share) {
    this->share = share;
}
double Cripto::getPrice() {
    return this->price;
}
void Cripto::setPrice(double price) {
    this->price = price;
}
std::string Cripto::getName() {
    return this->name;
}
void Cripto::setName(std::string name) {
    this->name = name;
}
void Cripto::changePrice() {
    if (getShare() <= 0) {
        std::cerr << "Erro: share deve ser maior que zero." << std::endl;
        return;
    }
    constexpr double baseFactor = 1.0;
    constexpr double scalingFactor = 1e6;
    double demand = getDemand();
    double share = getShare();
    double denominator = share + demand;
    if (denominator == 0) {
        std::cerr << "Erro: denominador é zero. Verifique os valores de share e demand." << std::endl;
        return;
    }
    price = scalingFactor * baseFactor * (demand / denominator);
    std::cout << "Debug - Demand: " << demand << ", Share: " << share << ", Denominator: " << denominator << std::endl;
    std::cout << "Novo preço: " << price << std::endl;
}
void Cripto::sendCriptoJson() {
    CURL *curl;
    CURLcode res;
    std::string json_data = "{"
        "\"name\": \"" + getName() + "\", "
        "\"price\": \"" + std::to_string(getPrice()) + "\", "
        "\"share\": " + std::to_string(getShare()) + ", "
        "\"demand\": " + std::to_string(getDemand()) + ", "
    "}";

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/api/simulator/cripto");


        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());

        struct curl_slist *headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "JSON enviado com sucesso!" << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Falha ao inicializar CURL." << std::endl;
    }
}
