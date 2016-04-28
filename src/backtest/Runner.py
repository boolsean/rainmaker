import sys
import QuandlDataSource

class Runner(object):
    def __init__(self, data, data_name):
        self._data = data
        self._data_name = data_name
        self._strategies = list()
        pass

    def add_strategy(self, strat):
        self._strategies.append(strat)

    def start(self):
        if self._data is None:
            print "Runner - no data"
            return


        for i, r in self._data.iterrows():
            for s in self._strategies:
                s.on_data(self._data_name, i, r, self)


        for s in self._strategies:
            s.on_complete()


        print "Runner completed run"

    def stop(self):
        sys.exit(0)



