# Write your MySQL query statement below

select a1.sell_date , count(distinct a1.product) as num_sold , GROUP_CONCAT( distinct a1.product order by a1.product asc) as products  from Activities a1 group by sell_date;