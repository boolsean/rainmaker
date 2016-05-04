#pragma once


namespace kg {
namespace trading {

class ExchOrder;
class IExchangeClient;

class IExchange {

public:
    virtual ~IExchange(){}

    virtual bool init()=0;
    virtual bool start()=0;
    virtual bool stop()=0;
    virtual bool addExchangeClient(IExchangeClient* client)=0;
    virtual bool sendOrder(ExchOrder* order)=0;
    virtual bool cancelOrder(ExchOrder* order)=0;

protected:

private:


};
}
} // close namespace kg
