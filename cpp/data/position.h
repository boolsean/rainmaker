#pragma once

#include <string>
#include <sstream>

namespace kg {
namespace data {

class Position {

public:
    Position();
    Position(const std::string& sym, char side, int qty, double price);

    void setSymbol(const std::string& val)  { _symbol = val; }
    void setSide(char val)                  { _side = val; }
    void setQuantity(int val)               { _qty = val; }
    void setPrice(double val)               { _price = val; }

    const std::string& getSymbol() const { return _symbol; }
    const char getSide() const { return _side; }
    const int getQuantity() const { return _qty; }
    const double getPrice() const { return _price; }

protected:

private:
    std::string _symbol;
    char _side;
    int _qty;
    double _price;
};

std::ostream& operator<<(std::ostream& os, const Position& p);

} // close namespace data
} // close namespace kg
