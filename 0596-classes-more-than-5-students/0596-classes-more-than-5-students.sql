# Write your MySQL query statement below
# select class from Courses group by class having count(student)>=5 ;
select class from (select class , count(student) as num from courses group by class) as temp where num>=5;