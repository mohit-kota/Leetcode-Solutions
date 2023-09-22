# Write your MySQL query statement below


select t2.name as Department , t1.name as Employee , t1.Salary as Salary from Employee t1 join Department t2 on t2.id = t1.departmentId where 3 > (select count(distinct e1.Salary) from Employee e1 where e1.Salary > t1.Salary and e1.DepartmentId = t1.DepartmentId);