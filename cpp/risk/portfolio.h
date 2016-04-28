#pragma once

#include "position.h"
#include <list>

namespace kg {
namespace risk {

class Portfolio {
public:
    Portfolio();

    void addPosition(const kg::data::Position& pos);
    void printHistory() const;

protected:
    double getPnl() const;
    std::list<kg::data::Position> _positions;

private:
};

} // close namespace risk
} // close namespace kg
