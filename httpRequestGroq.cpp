#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "httpRequestGroq.h"

using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

void RequestGroq::sendRequest(const std::string& prompt, std::string& response) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::string jsonData = R"({
        "model": "llama-3.3-70b-versatile",
        "messages": [{
            "role": "user",
            "content": ")" + prompt + R"("
        }]
    })";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.groq.com/openai/v1/chat/completions");

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Authorization: Bearer yourGroqTokenHere");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Erro na requisicaoo: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            try {
                auto parsed = json::parse(readBuffer);
                response = parsed["choices"][0]["message"]["content"];
            }
            catch (const std::exception& e) {
                std::cerr << "Erro ao processar JSON: " << e.what() << std::endl;
            }
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
}