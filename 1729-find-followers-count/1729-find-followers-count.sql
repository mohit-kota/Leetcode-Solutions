# Write your MySQL query statement below
# select * from  (select user_id , count(*) as followers_count from Followers group by user_id)  as temp order by user_id  asc;

select user_id , count(user_id) as followers_count from Followers group by user_id order by user_id asc;