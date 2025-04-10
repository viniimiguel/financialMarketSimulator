#include "../headerFiles/stock.h"
#include "../headerFiles/cripto.h"

#ifndef EVENTS_H
#define EVENTS_H
class Event {
public:
    void randomize(std::vector<Stock> &stocks, double percent, double variation);
    void changePriceBySector(const std::string& targetSector);
    void changeBadPriceBySector(const std::string& targetSector);

private:
};
#endif //EVENTS_H
