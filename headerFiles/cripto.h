
#ifndef CRIPTO_H
#define CRIPTO_H
#include <string>
#include <vector>

class Cripto {
private:
    std::string name;
    double price;
    long long share;
    long long demand;
public:
    Cripto(const std::string &name, double price, long long share, long long demand)
        : name(name),
          price(price),
          share(share),
          demand(demand) {
    }
    void setName(std::string name);
    void setPrice(double price);
    void setShare(long long share);
    void setDemand(long long demand);
    std::string getName();
    double getPrice();
    long long getShare();
    long long getDemand();
    void sendCriptoJson();
    void changePrice();
};
extern std::vector<Cripto> criptos;
#endif
