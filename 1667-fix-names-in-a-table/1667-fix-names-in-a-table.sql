# Write your MySQL query statement below
select user_id , CONCAT(UPPER(LEFT(name, 1)) ,
        LOWER(RIGHT(name, LENGTH(name) - 1))) as name from Users order by user_id;