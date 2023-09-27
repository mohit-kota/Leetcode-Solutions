# Write your MySQL query statement below
select max(s1.salary) as SecondHighestSalary from Employee s1  where 1 = (select count(distinct s2.salary) from Employee s2 where s2.salary > s1.salary) order by s1.salary desc limit 1 ; 

