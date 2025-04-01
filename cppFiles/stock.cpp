#include "../headerFiles/stock.h"
#include <curl/curl.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>


void Stock::setTicker(std::string ticker) {
    this->ticker = ticker;
}
void Stock::setCompanyName(std::string companyName) {
    this->companyName = companyName;
}
void Stock::setPrice(long long price) {
    this->price = price;
}
void Stock::setTotalShares(long long totalShares) {
    this->totalShares = totalShares;
}
void Stock::setTotalDemand(long long totalDemand) {
    this->totalDemand = totalDemand;
}
void Stock::setFormatedPrice(double price) {
    this->formatedPrice = price;
}
void Stock::setVariation(double variation) {
    this->variation = variation;
}

double Stock::getFormatedPrice() {
    return this->formatedPrice;
}
std::string Stock::getCompanyName() {
    return companyName;
}
std::string Stock::getTicker() {
    return ticker;
}
long long Stock::getTotalShares() {
    return totalShares;
}
long long Stock::getPrice() {
    return price;
}
long long Stock::getTotalDemand() {
    return totalDemand;
}
double Stock::getVariation() {
    return variation;
}

void Stock::changePrice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-0.005, 0.005);
    double variable = dist(gen);
    price = static_cast<long long>(price * (1.0 + variable) + 0.5);
    std::cout << "Variação: " << variable * 100 << "% | Novo Preço: " << price << std::endl;
    variation = variable * 100;
}


void Stock::sendStockJson() {
    CURL *curl;
    CURLcode res;
    std::string json_data = "{"
        "\"ticker\": \"" + getTicker() + "\", "
        "\"companyName\": \"" + getCompanyName() + "\", "
        "\"price\": " + std::to_string(getFormatedPrice()) + ", "
        "\"shares\": " + std::to_string(getTotalShares()) + ", "
        "\"demand\": " + std::to_string(getTotalDemand()) + ", "
        "\"variation\": " + std::to_string(getVariation()) +


    "}";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/api/simulator/stock");


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

    curl_global_cleanup();
}