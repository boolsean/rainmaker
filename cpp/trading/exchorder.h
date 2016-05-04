#pragma once

#include <string>

namespace kg {
namespace trading {

class ExchOrder {
public:
    enum Action {
        NEW,
        CXL
    };

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

    unsigned    _id;
    UpdateType  _updateType;
    unsigned    _quantity;
    double      _price;
    char        _reason[64];
};

}
}
