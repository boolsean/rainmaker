#include <iostream>
#include <memory>
#include "logger.h"
#include "exchorder.h"
#include "iexchangeclient.h"
#include "iexchange.h"
#include "simexchange.h"

#include <boost/thread/thread.hpp>


class TestExchangeClient : public kg::trading::IExchangeClient {
public:
    void onExchangeUpdate(kg::trading::ExchOrderUpdate* update) {
        LOG_INFO("TestExchangeClient onExchangeUpdate");
        LOG_INFO(*update);
    }

    std::string getName() const {
        return "TestClient";
    }

protected:


private:
};


int main() {

    kg::trading::IExchange* exchange = new kg::trading::SimExchange();

    kg::trading::IExchangeClient* client = new TestExchangeClient();

    exchange->init();
    exchange->start();
    exchange->addExchangeClient(client);

    std::shared_ptr<kg::trading::ExchOrder> first(new kg::trading::ExchOrder());


    kg::trading::ExchOrder* firstOrder = new kg::trading::ExchOrder();
    firstOrder->_id = 232881;
    firstOrder->_action = kg::trading::ExchOrder::NEW;
    firstOrder->_quantity = 10;
    firstOrder->_price = 100.10;
    firstOrder->_side = 'B';
    firstOrder->_symbol = "AAPL";
    LOG_INFO("sending" << *firstOrder);
    exchange->sendOrder(firstOrder);

    firstOrder->_id++;
    LOG_INFO("sending" << *firstOrder);
    exchange->sendOrder(firstOrder);
    boost::this_thread::sleep_for(boost::chrono::seconds(10));

    return 0;
}
