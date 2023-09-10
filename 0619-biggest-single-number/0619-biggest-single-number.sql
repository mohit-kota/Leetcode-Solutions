# Write your MySQL query statement below
# select max(num) as num from MyNumbers  group by num having count(num) =1  order by num desc limit 1;
select ( select num from MyNumbers
group by num
having count(num) =1
order by num desc
limit 1) as num
from
dual