#pragma once

#include <string>

namespace kg {
namespace trading {

class ExchOrderUpdate;

class IExchangeClient {
public:
    virtual ~IExchangeClient(){}

    virtual void onExchangeUpdate(ExchOrderUpdate* update)=0;
    virtual std::string getName() const=0;
};
}
}
