#include <iostream>
#include <string>
#include <boost/thread/thread.hpp>

bool flag = false;

void printfiveTimes() {
    for (int i = 0; i < 5; i++) {
        std::cout << "i:" << i;
    }
    std::cout << std::endl;
    flag = true;
}

void print(unsigned x) {
    for(int i = 0; i < x; i++) {
        std::cout << "k:" << i;
    }
    std::cout << std::endl;
    flag = true;
}

int main() {

    boost::thread t(printfiveTimes);
    t.detach();

    boost::thread u(print, 10);
    u.detach();


    while(flag == false) {
        std::cout << "j" << std::endl;
    }

    return 0;
}
