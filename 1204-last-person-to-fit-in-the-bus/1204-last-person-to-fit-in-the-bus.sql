# Write your MySQL query statement below
select t1.person_name from Queue t1 join Queue t2 where t1.turn >= t2.turn group by t1.turn having sum(t2.weight)<=1000 order by sum(t2.weight) desc limit 1;