#include "position.h"
#include "portfolio.h"
#include <iostream>


int main() {
    std::cout << "hello" << std::endl;

    kg::risk::Portfolio portf;
    kg::data::Position pos("AAPL", 'B', 100, 98.92);

    portf.addPosition(pos);
    pos.setSide('S');
    pos.setPrice(pos.getPrice()+.05);
    portf.addPosition(pos);

    portf.printHistory();
    return 0;
}
