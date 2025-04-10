
#ifndef CRIPTO_H
#define CRIPTO_H
#include <string>
#include <vector>

class Cripto {
private:
    std::string name;
    long long price;
    long long share;
    long long demand;
public:
    Cripto(const std::string &name, long long price, long long share, long long demand)
        : name(name),
          price(price),
          share(share),
          demand(demand) {
    }
    void setName(std::string name);
    void setPrice(long long price);
    void setShare(long long share);
    void setDemand(long long demand);
    std::string getName();
    long long getPrice();
    long long getShare();
    long long getDemand();
};
extern std::vector<Cripto> criptos;
#endif
