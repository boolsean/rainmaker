#include "iexchange.h"
#include "iexchangeclient.h"
#include "exchorder.h"

#include "linkedqueue.h"

namespace boost {
class thread;
}

namespace kg {
namespace trading {

class SimExchange : public IExchange {

public:
    SimExchange();
    ~SimExchange();

    bool init();
    bool start();
    bool stop();
    bool addExchangeClient(IExchangeClient* client);
    bool sendOrder(ExchOrder* order);
    bool cancelOrder(ExchOrder* order);

protected:

    void run();


    // simulated order logic
    ExchOrderUpdate* getOrderFilledUpdate(ExchOrder* order);

private:
    IExchangeClient*                        _client;
    bool                                    _stopRequested;
    kg::util::LinkedQueue<ExchOrder*> _orders;
    boost::thread*                          _orderThread;
};

}
}
