sqlldr skip=2 bad=bad_client_master.log data=csv/client_master.csv control=ctl/client_master.ctl userid=jpandya discard=discard_client_master.log
sqlldr skip=1 bad=bad_product_master.log data=csv/product_master.csv control=ctl/product_master.ctl userid=jpandya discard=discard_product_master.log
sqlldr data=csv/salesman_master.csv control=ctl/salesman_master.ctl skip=1 bad=salesman_master.bad discard=salesman_master.log
sqlldr data=csv/sales_order.csv control=ctl/sales_order.ctl skip=1 bad=sales_order.bad discard=sales_order.log
sqlldr data=csv/sales_order_details.csv control=ctl/sales_order_details.ctl skip=1 bad=sales_order_details.bad discard=sales_order_details.log
