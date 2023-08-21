# Write your MySQL query statement below
select e1.name , e2.bonus from Employee e1 left outer join Bonus e2 on e1.empId = e2.empId where e2.bonus<1000 or e2.bonus is NULL;  
