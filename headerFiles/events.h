#include "../headerFiles/stock.h"
#include "../headerFiles/cripto.h"

#ifndef EVENTS_H
#define EVENTS_H
class Event {
public:
    void randomize(std::vector<Stock> &stocks, double percent, double variation);
    void randomizeGain(std::vector<Stock> &stocks);
    void randomizeFall(std::vector<Stock> &stocks);
    void randomizeBigGain(std::vector<Stock> &stocks);
    void randomizeBigFall(std::vector<Stock> &stocks);
private:
};
#endif //EVENTS_H
