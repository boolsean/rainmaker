import sys
sys.path.append("../")
sys.path.append("../datasource/")

import Runner
import Portfolio
import QuandlDataSource

class PrintStrategy(object):
    def __init__(self):
        self._portfolio = Portfolio.Portfolio()
        pass

    def on_data(self, name, index, data, parent):
        print "PrintStrategy::on_data"
        print index.isoformat() + " - " + name + "-" + str(data["Close"])
        self._portfolio.add_trade(name, index, "B", 100, data["Close"])

    def on_complete(self):
        print "PrintStrategy::on_complete"
        self._portfolio.print_orders()


qds = QuandlDataSource.QuandlDataSource()

sec_name = "WIKI/AAPL"

data = qds.get_stock_pd(sec_name, start_date='2015-1-1', end_date='2015-2-5')

strategy = PrintStrategy()


runner = Runner.Runner(data, sec_name)
runner.add_strategy(strategy)

runner.start()



