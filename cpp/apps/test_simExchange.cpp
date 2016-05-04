#include <iostream>
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
    }

    std::string getName() const {
        return "TestClient";
    }

protected:


private:


};


int main() {

    kg::trading::IExchange* exchange = new kg::trading::SimExchange();

    exchange->init();
    exchange->start();

    return 0;
}
