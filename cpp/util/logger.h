#pragma once

#include <iostream>
#include <sstream>

#include <ctime>
#include <sys/time.h>

namespace kg {
namespace util {

class Logger {
public:
    void init() {
    }

    void static onLog(const char* s) {
        timeval curTime;
        gettimeofday(&curTime, NULL);
        int mills = curTime.tv_usec / 1000;
        char buffer[32];
        strftime(buffer, sizeof(buffer), "[%Y%m%d:%H:%M:%S:", localtime(&curTime.tv_sec));
        std::cout << buffer << mills << "] "<< s << std::endl;
    }

protected:


private:

};
}
} // close namespace kg


#define LOG_INFO(x)     do {                    \
    std::stringstream os;                       \
    os << "[INFO ]["<< __func__ << "] " << x << std::endl;         \
    kg::util::Logger::onLog(os.str().c_str());  \
    } while (false);

#define LOG_ERROR(x)     do {                   \
    std::stringstream os;                       \
    os << "[ERROR][" << __func__ << "] " << x << std::endl;         \
    kg::util::Logger::onLog(os.str().c_str());  \
    } while (false);


