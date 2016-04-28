#include "portfolio.h"

#include <iostream>

namespace kg {
namespace risk {

Portfolio::Portfolio()
    :   _positions()
{}

void Portfolio::addPosition(const kg::data::Position& pos) {

    _positions.push_back(pos);
}

void Portfolio::printHistory() const {
    std::cout << "Portfolio.printHistory IMPLEMENT ME" << std::endl;
    for(std::list<kg::data::Position>::const_iterator it = _positions.begin();
            it != _positions.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "pnl:" << getPnl() << std::endl;
}

double Portfolio::getPnl() const {
    double pnl = .0;
    for(std::list<kg::data::Position>::const_iterator it = _positions.begin();
            it != _positions.end(); ++it) {
        const kg::data::Position& p = *it;
        if (p.getSide() == 'S') {
            pnl += (p.getPrice()*p.getQuantity());
        }
        else {
            pnl -= (p.getPrice()*p.getQuantity());
        }
    }
    return pnl;
}



} // close namespace risk
} // close namespace kg
