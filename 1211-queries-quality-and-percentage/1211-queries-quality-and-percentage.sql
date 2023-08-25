# Write your MySQL query statement below
select e1.query_name , ROUND(AVG(e1.rating/e1.position),2) quality , ROUND(AVG(e1.rating < 3) * 100, 2) as poor_query_percentage from Queries e1  group by e1.query_name;