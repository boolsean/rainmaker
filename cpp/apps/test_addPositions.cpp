#include "position.h"
#include "portfolio.h"
#include <iostream>


int main() {
    std::cout << "hello" << std::endl;

    kg::risk::Portfolio portf;
    kg::data::Position pos("AAPL", 'B', 100, 98.92);

    portf.addPosition(pos);
    pos.setQuantity(200);
    pos.setPrice(pos.getPrice()+.05);
    portf.addPosition(pos);

    pos.setSide('S');
    pos.setQuantity(200);
    pos.setPrice(pos.getPrice()+.04);
    portf.addPosition(pos);

    pos.setQuantity(100);
    pos.setPrice(pos.getPrice()+.02);
    portf.addPosition(pos);
    portf.printHistory();
    portf.printLineByLineSummary();
    return 0;
}
