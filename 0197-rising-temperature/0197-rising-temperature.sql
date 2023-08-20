# Write your MySQL query statement below
select DISTINCT w1.id  as ID from Weather w1  join Weather w on DATEDIFF(w1.recordDate,w.recordDate) = 1 and w1.Temperature > w.Temperature;