#pragma once

#include <string>

namespace kg {
namespace trading {

class ExchOrder {
public:
    enum Action {
        NEW,
        CXL,
        UNDEF
    };

    ExchOrder()
        :   _id(0), _action(UNDEF), _quantity(0), _price(.0), _side('B'), _symbol("")
    {}

    ExchOrder(unsigned id, Action action, unsigned qty, double px, char side,
            const std::string& symbol)
        :   _id(id), _action(action), _quantity(qty), _price(px), _side(side), _symbol(symbol)
    {}

    unsigned        _id;
    Action          _action;
    unsigned        _quantity;
    double          _price;
    char            _side;
    std::string     _symbol;

private:

};

class ExchOrderUpdate {
public:
    enum UpdateType {
        ACK,
        PARTIAL_FILL,
        FILL,
        REJECT,
        CANCELLED
    };

    ExchOrderUpdate()
    {}

    ExchOrderUpdate(unsigned id, UpdateType updateType, unsigned qty,
            double px, const std::string& symbol)
        :   _id(id), _updateType(updateType), _quantity(qty), _price(px)
    {
        strncpy(_reason, symbol.c_str(), sizeof(_reason));
    }

    unsigned    _id;
    UpdateType  _updateType;
    unsigned    _quantity;
    double      _price;
    char        _reason[64];
};

}
}
