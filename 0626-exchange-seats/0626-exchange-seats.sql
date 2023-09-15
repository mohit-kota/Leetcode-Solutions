# Write your MySQL query statement below
select s1.id-1 as id ,s1.student from Seat s1 where s1.id mod 2 = 0
union 
select s2.id+1 as id ,s2.student from Seat s2 where s2.id mod 2 = 1 and s2.id != (select MAX(id) from Seat)
union 
select s3.id as id   ,s3.student from Seat s3 where s3.id mod 2 = 1 and s3.id = (select max(id) from Seat) 
order by id asc;  