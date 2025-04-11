#ifndef GROQ_H
#define GROQ_H
#include <string>
class Groq {
private:

public:
    std::string sendBadNotice(const std::string& sector);
    std::string sendGodNotice(const std::string& sector);
    void sendJsonNotice(const std::string& notice);
    void processAndSendNotice(const std::string& sector, bool isPositive);

};
#endif
