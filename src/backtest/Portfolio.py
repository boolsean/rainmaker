

class Portfolio(object):
    def __init__(self):
        self._orders_by_name = dict()
        pass

    def add_trade(self, name, date, side, qty, px):
        if(self._orders_by_name.has_key(name) is False):
            new_list = list()
            self._orders_by_name[name] = list()

        self._orders_by_name[name].append((date, side, qty, px))

    def calc_pnl(self, name):
        orders = self._orders_by_name[name]
        agg_pnl = 0.0
        for o in orders:
            side = -1
            if o[1][0] == 'S':
                side = 1
            cur_pnl = o[3]*o[2]*side
            print "calced pnl:%f from side=%d qty=%d px=%f" % (cur_pnl, side, o[2], o[3])

            agg_pnl += cur_pnl
        return agg_pnl

    def print_orders(self):

        for k, v in self._orders_by_name.iteritems():
            print k
            print self.calc_pnl(k)
            for o in v:
                print o
        pass

