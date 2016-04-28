#include "position.h"

namespace kg {
namespace data {

Position::Position()
    :   _symbol(), _side(0), _qty(0), _price(.0)
{}

Position::Position(const std::string& sym, char side, int qty, double price)
    :   _symbol(sym), _side(side), _qty(qty), _price(price)
{}

std::ostream& operator<<(std::ostream& os, const Position& p) {
    os << "Position"
        << "\nsymbol ...... " << p.getSymbol()
        << "\nside ........ " << p.getSide()
        << "\nqty ......... " << p.getQuantity()
        << "\nprice ....... " << p.getPrice();
    return os;
}


} // close namespace data
} // close namespace kg
