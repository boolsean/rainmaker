#include "linkedqueue.h"
#include "logger.h"

#include <string>
#include <iostream>



template<typename T>
void popAndPrint(kg::util::LinkedQueue<T>& vals) {
    std::cout << "popAndPrint size:" << vals.size() << std::endl;
    T tmp;
    while(vals.getFront(tmp)) {
        std::cout << "popAndPrint val:" << tmp << std::endl;
    }
}

void test_LQStrings() {
    kg::util::LinkedQueue<std::string> words;
    words.addBack("hello");
    words.addBack("bye");
    words.addBack("world");
    popAndPrint(words);
}

void test_LQNums() {
    kg::util::LinkedQueue<int> nums;
    nums.addBack(12);
    nums.addBack(20);
    nums.addBack(-10);
    nums.addBack(100);
    popAndPrint(nums);
}

int main(int argc, char** argv) {
    LOG_INFO("program starting...");
    test_LQNums();
    test_LQStrings();

    LOG_ERROR("program starting...");

    return 0;
}
