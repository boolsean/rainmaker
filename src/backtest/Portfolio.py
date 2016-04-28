

class Portfolio(object):
    def __init__(self):
        self._orders_by_name = dict()
        pass

    def add_trade(self, name, date, side, qty, px):
        if(self._orders_by_name.has_key(name) is False):
            new_list = list()
            self._orders_by_name[name] = list()

        self._orders_by_name[name].append((date, side, qty, px))


    def print_orders(self):

        for k, v in self._orders_by_name.iteritems():
            print k, v
        pass

