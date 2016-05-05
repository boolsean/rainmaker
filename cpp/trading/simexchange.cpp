#include "simexchange.h"
#include "logger.h"

#include <boost/thread/thread.hpp>


namespace kg {
namespace trading {


SimExchange::SimExchange()
    :   _client(nullptr),
        _stopRequested(false),
        _orders(),
        _orderThread(nullptr)
{}

SimExchange::~SimExchange() {
    if(_orderThread)
        delete _orderThread;
}

bool SimExchange::init() {
    return true;
}

bool SimExchange::start() {
    LOG_INFO("invoked... creating order thread");
    _orderThread = new boost::thread(boost::bind(&SimExchange::run, this));
    _orderThread->detach();
    return true;
}

bool SimExchange::stop() {
    _stopRequested = true;
    return true;
}

bool SimExchange::addExchangeClient(IExchangeClient* client) {
    if (client == nullptr) {
        LOG_ERROR("addExchangeClient client null");
        return false;
    }

    if (_client == nullptr) {
        LOG_INFO("addExchangeClient added new client:" << client->getName());
    }
    else {
        LOG_ERROR("addExchangeClient replacing with new client:" << client->getName());
    }
    _client = client;
    return true;
}

bool SimExchange::sendOrder(ExchOrder* order) {
    if (!order) {
        return false;
    }
    _orders.addBack(order);
    return true;
}

bool SimExchange::cancelOrder(ExchOrder* order) {
    if (!order) {
        return false;
    }
    _orders.addBack(order);
    return true;
}

void SimExchange::run() {
    LOG_INFO("run invoked");

    for (;;) {

        if (!_orders.isEmpty()) {
            ExchOrder* order=nullptr;
            if(!_orders.getFront(order)) {
                LOG_ERROR("run failed to get an order from order queue");
                continue;
            }
            else {
                LOG_INFO("found order with id:" << order->_id);
            }

            ExchOrderUpdate* update = getOrderFilledUpdate(order);

            if(update) {
                LOG_INFO("sending update to client");
                if(_client)
                    _client->onExchangeUpdate(update);
                else {
                    LOG_ERROR("no client set");
                }

                delete update;
            }
        }
        else {
            boost::this_thread::sleep_for(boost::chrono::seconds(5));
        }

        if (_stopRequested) {
            LOG_INFO("stop requested");
            break;
        }
    }
}

ExchOrderUpdate* SimExchange::getOrderFilledUpdate(ExchOrder* order) {

    ExchOrderUpdate* update = nullptr;

    if(!order)
        return update;

    update = new ExchOrderUpdate();
    update->_id = order->_id;
    update->_updateType = ExchOrderUpdate::FILL;
    update->_quantity = order->_quantity;
    update->_price = order->_price;
    strncpy(update->_reason, "DONE", 4);

    return update;

}


}
}
