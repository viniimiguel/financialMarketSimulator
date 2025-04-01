#include "../headerFiles/util.h"

double Util::convertCentsToUnit(long long cents) {
    return static_cast<double>(cents) / 100.0;
}
