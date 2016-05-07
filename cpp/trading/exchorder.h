#pragma once

#include <string>
#include <sstream>

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

    void setId(unsigned id)         { _id = id; }
    void setAction(Action action)   { _action = action; }
    void setQuantity(unsigned qty)  { _quantity = qty; }
    void setPrice(double px)        { _price = px; }
    void setSide(char side)         { _side = side; }
    void setSymbol(const std::string& symbol)   { _symbol = symbol; }

    unsigned getId() const          { return _id; }
    Action getAction() const        { return _action; }
    unsigned getQuantity() const    { return _quantity; }
    double getPrice() const         { return _price; }
    char getSide() const            { return _side; }
    const char* getSymbol() const   { return _symbol.c_str(); }

    unsigned        _id;
    Action          _action;
    unsigned        _quantity;
    double          _price;
    char            _side;
    std::string     _symbol;

private:

};

std::ostream& operator<<(std::ostream& os, const ExchOrder& o);

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
            double px, const std::string& reason)
        :   _id(id), _updateType(updateType), _quantity(qty), _price(px)
    {
        strncpy(_reason, reason.c_str(), sizeof(_reason));
    }

    void setId(unsigned id) { _id = id; }
    void setUpdateType(UpdateType updateType) { _updateType = updateType; }
    void setQuantity(unsigned qty) { _quantity = qty; }
    void setPrice(double px) { _price = px; }
    void setReason(const std::string& reason) { strncpy(_reason, reason.c_str(), reason.size()); }

    unsigned getId() const { return _id; }
    UpdateType getUpdateType() const { return _updateType; }
    unsigned getQuantity() const { return _quantity; }
    double getPrice() const { return _price; }
    const char* getReason() const { return _reason; }

    unsigned    _id;
    UpdateType  _updateType;
    unsigned    _quantity;
    double      _price;
    char        _reason[64];
};

std::ostream& operator<<(std::ostream& os, const ExchOrderUpdate& u);

}
}
