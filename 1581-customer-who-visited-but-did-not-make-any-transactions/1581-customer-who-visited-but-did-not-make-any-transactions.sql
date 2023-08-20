# Write your MySQL query statement below

select vis.customer_id , count(vis.visit_id) as count_no_trans from Visits vis left join Transactions trans on vis.visit_id = trans.visit_id where trans.transaction_id is NULL group by vis.customer_id;

# SELECT customer_id, COUNT(v.visit_id) as count_no_trans 
# FROM Visits v
# LEFT JOIN Transactions t ON v.visit_id = t.visit_id
# WHERE transaction_id IS NULL
# GROUP BY customer_id