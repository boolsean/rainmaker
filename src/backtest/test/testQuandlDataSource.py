
import sys;
sys.path.append("../datasource/")

import QuandlDataSource



ds = QuandlDataSource.QuandlDataSource()
print ds.get_stock_pd('WIKI/AAPL', start_date='2014-1-1', end_date='2014-1-5')
print ds.get_stock_close_pd('WIKI/AAPL', start_date='2014-1-1', end_date='2014-1-5')
