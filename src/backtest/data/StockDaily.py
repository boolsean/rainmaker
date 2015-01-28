import sys

# accepts a pandas object
class StockDaily(object):
    def __init__(self, symbol, raw):
        self._symbol = symbol
        self._raw = raw

        print self._raw
        pass

    def date(self):
        return self._raw["Date"]

    def symbol(self):
        return self._symbol

    def open(self):
        return self._raw["Open"]

    def high(self):
        return self._raw["High"]

    def close(self):
        return self._raw["Close"]

    def volume(self):
        return self._raw["Volume"]

    def raw(self):
        return self._raw


    def pretty(self):
        print self.get_pretty()

    def get_pretty(self):
        return "S=%s C=%f" % (self.symbol(), self.close())



