#include "../headerFiles/stock.h"
#include <curl/curl.h>
#include <iostream>
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

void Stock::sendStockJson() {
    CURL *curl;
    CURLcode res;
    std::string json_data = "{"
        "\"ticker\": \"" + getTicker() + "\", "
        "\"companyName\": \"" + getCompanyName() + "\", "
        "\"price\": " + std::to_string(getPrice()) + ", "
        "\"shares\": " + std::to_string(getTotalShares()) + ", "
        "\"demand\": " + std::to_string(getTotalDemand()) +
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
