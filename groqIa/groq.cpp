#include "groq.h"
#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include "api.h"


size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

std::string sendRequest(const std::string& sector, const std::string& prompt) {
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        const std::string url = "https://api.groq.com/openai/v1/chat/completions";

        std::ostringstream bodyStream;
        bodyStream << R"({
            "model": "llama-3.3-70b-versatile",
            "messages": [
                {
                    "role": "user",
                    "content": ")" << prompt << " setor: " << sector << R"("
                }
            ]
        })";

        std::string body = bodyStream.str();

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, ("Authorization: Bearer " + api).c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Erro ao fazer o request: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Resposta bruta da API: " << response << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Erro ao inicializar CURL" << std::endl;
    }

    return response;
}

std::string Groq::sendGodNotice(const std::string& sector) {
    const std::string prompt = "Crie uma mensagem otimista e abrangente que destaque eventos, avanços ou perspectivas positivas relacionados a um setor específico. A mensagem deve enfatizar as oportunidades e o potencial de crescimento do setor como um todo, sem mencionar empresas específicas. O tom deve ser profissional, acessível e encorajador, com o objetivo de inspirar confiança e influenciar positivamente o mercado financeiro.";
    return sendRequest(sector, prompt);
}

std::string Groq::sendBadNotice(const std::string& sector) {
    const std::string prompt = "Crie uma mensagem que destaque desafios, problemas ou tendências negativas relacionados a um setor específico. A mensagem deve abordar os fatores de risco ou preocupações que possam impactar o desempenho do setor como um todo, sem mencionar empresas específicas. O tom deve ser profissional e informativo, visando alertar sobre possíveis impactos no mercado financeiro.";
    return sendRequest(sector, prompt);
}

void Groq::sendJsonNotice(const std::string& notice) {
    CURL *curl;
    CURLcode res;
    std::string json_data = "{"
        "\"ticker\": \"" + notice+ "\", "
    "}";

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/api/simulator/groqNotice");


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
