"""
QuandlDataSource.py
    Defines a driver that interfaces with the quandl website to download
    EOD stock data.  It returns a set of pandas dataframe objects as its results
    If user has a quandl token defined as an environment variable, it will submit
    this key to quandl
"""

import Quandl
import os

class QuandlDataSource(object):
    def __init__(self):
        self.token = None
        if os.environ.has_key('QUANDL_TOKEN'):
            self.token = os.environ['QUANDL_TOKEN']

    def get_stock_pd(self, query="", source=None, start_date=None, end_date=None,
            fields=None):
        data = Quandl.get(query, authtoken=self.token, trim_start=start_date, trim_end=end_date)
        if fields is None:
            return data
        else:
            return data[fields]


    def get_stock_close_pd(self, query="", source=None, start_date=None, end_date=None,
            fields=None):
        return self.get_stock_pd(query, source, start_date, end_date, "Close")




