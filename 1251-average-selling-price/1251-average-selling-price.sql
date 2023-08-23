# Write your MySQL query statement below
select e1.product_id , ROUND(SUM(e2.units*e1.price)/SUM(e2.units),2) as average_price from Prices e1 join UnitsSold e2 on e2.product_id = e1.product_id and (e2.purchase_date between e1.start_date and e1.end_date) group by e1.product_id;