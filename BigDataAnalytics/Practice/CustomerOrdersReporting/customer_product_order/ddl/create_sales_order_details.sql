drop table sales_order_details;

create table sales_order_details
(s_order_no varchar2(6) references sales_order(s_order_no),
 product_no varchar2(6) references product_master(product_no),
 qty_order number(8),
 qty_disp number(8),
 product_rate number(10,2),
 primary key(s_order_no, product_no)
);

exit;
